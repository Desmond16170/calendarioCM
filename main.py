from kivy.app import App
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.boxlayout import BoxLayout
from kivy.storage.jsonstore import JsonStore
from kivy.uix.spinner import Spinner
from kivy.uix.textinput import TextInput
from datetime import datetime, timedelta

# Guardar y cargar respuestas
store = JsonStore('user_data.json')

# Funciones auxiliares
def get_user_responses():
    responses = {}
    if store.exists('conceiving'):
        responses['conceiving'] = store.get('conceiving')['answer']
    if store.exists('periods_regular'):
        responses['periods_regular'] = store.get('periods_regular')['answer']
    if store.exists('first_time_trying'):
        responses['first_time_trying'] = store.get('first_time_trying')['answer']
    if store.exists('last_period_date'):
        responses['last_period_date'] = store.get('last_period_date')['answer']
    if store.exists('flow_duration'):
        responses['flow_duration'] = store.get('flow_duration')['answer']
    return responses

def calculate_menstrual_calendar(last_period_date, flow_duration):
    try:
        start_date = datetime.strptime(last_period_date, '%d/%m/%Y')
    except ValueError:
        return None

    cycles = []
    for i in range(4):
        cycle_start = start_date + timedelta(days=i*(28+flow_duration))
        cycle_end = cycle_start + timedelta(days=flow_duration)
        cycles.append((cycle_start, cycle_end))

    return cycles

def calculate_days_until_next_cycle(last_period_date, flow_duration):
    try:
        start_date = datetime.strptime(last_period_date, '%d/%m/%Y')
    except ValueError:
        return None

    today = datetime.now()
    next_cycle_start = start_date

    while next_cycle_start < today:
        next_cycle_start += timedelta(days=(28+flow_duration))

    return (next_cycle_start - today).days

# Definición de pantallas
class DatePicker(BoxLayout):
    def __init__(self, **kwargs):
        super(DatePicker, self).__init__(**kwargs)
        self.orientation = 'horizontal'
        
        self.day = Spinner(text='Day', values=[str(i) for i in range(1, 32)])
        self.month = Spinner(text='Month', values=[str(i) for i in range(1, 13)])
        self.year = TextInput(text='Year', multiline=False)
        
        self.add_widget(self.day)
        self.add_widget(self.month)
        self.add_widget(self.year)
    
    def get_date(self):
        return f"{self.day.text}/{self.month.text}/{self.year.text}"
    
class MainScreen(Screen):
    def __init__(self, **kwargs):
        super(MainScreen, self).__init__(**kwargs)
        layout = BoxLayout(orientation='vertical', spacing=10)
        
        # Botón para "Quedarme embarazada"
        btn_embarazada = Button(text='Quedarme embarazada')
        btn_embarazada.bind(on_press=self.change_to_quedarme_embarazada)
        layout.add_widget(btn_embarazada)
        
        # Botón para "Seguimiento de embarazo"
        btn_seguimiento = Button(text='Seguimiento de embarazo')
        btn_seguimiento.bind(on_press=self.change_to_seguimiento_embarazo)
        layout.add_widget(btn_seguimiento)
        
        self.add_widget(layout)
    
    def change_to_quedarme_embarazada(self, instance):
        self.manager.current = 'question1'

    def change_to_seguimiento_embarazo(self, instance):
        self.manager.current = 'seguimiento_embarazo'


class Question1(Screen):
    def __init__(self, **kwargs):
        super(Question1, self).__init__(**kwargs)
        layout = BoxLayout(orientation='vertical')
        label = Label(text='¿Intentas concebir durante tus días más fértiles?')
        layout.add_widget(label)
        options = ['Sí', 'No', 'No sé cuándo tienen lugar mis días más fértiles']
        for option in options:
            btn = Button(text=option)
            btn.bind(on_press=self.store_answer)
            layout.add_widget(btn)
        self.add_widget(layout)

    def store_answer(self, instance):
        store.put('conceiving', answer=instance.text)
        self.manager.current = 'question2' 

class Question2(Screen):
    def __init__(self, **kwargs):
        super(Question2, self).__init__(**kwargs)
        layout = BoxLayout(orientation='vertical')
        label = Label(text='¿Tus periodos son regulares?')
        layout.add_widget(label)
        options = ['Sí', 'No', 'No lo sé']
        for option in options:
            btn = Button(text=option)
            btn.bind(on_press=self.store_answer)
            layout.add_widget(btn)
        self.add_widget(layout)

    def store_answer(self, instance):
        store.put('periods_regular', answer=instance.text)
        if instance.text == 'No':
            self.manager.current = 'question_flow_duration'
        else:
            self.manager.current = 'question3'

class QuestionFlowDuration(Screen):
    def __init__(self, **kwargs):
        super(QuestionFlowDuration, self).__init__(**kwargs)
        layout = BoxLayout(orientation='vertical')
        label = Label(text='¿Cuántos días te dura aproximadamente el flujo menstrual?')
        layout.add_widget(label)
        self.flow_input = TextInput(multiline=False)
        layout.add_widget(self.flow_input)
        btn = Button(text='Siguiente')
        btn.bind(on_press=self.store_answer)
        layout.add_widget(btn)
        self.add_widget(layout)

    def store_answer(self, instance):
        flow_duration = self.flow_input.text
        if flow_duration.isdigit():
            store.put('flow_duration', answer=int(flow_duration))
            self.manager.current = 'question3'

class Question3(Screen):
    def __init__(self, **kwargs):
        super(Question3, self).__init__(**kwargs)
        layout = BoxLayout(orientation='vertical')
        label = Label(text='¿Es la primera vez que intentas concebir?')
        layout.add_widget(label)
        options = ['Sí', 'No, ya tengo hijos', 'No, he pasado por un aborto espontáneo o una interrupción del embarazo', 'Prefiero no contestar']
        for option in options:
            btn = Button(text=option)
            btn.bind(on_press=self.store_answer)
            layout.add_widget(btn)
        self.add_widget(layout)

    def store_answer(self, instance):
        store.put('first_time_trying', answer=instance.text)
        self.manager.current = 'results'

class ResultsScreen(Screen):
    def on_enter(self):
        responses = get_user_responses()
        layout = BoxLayout(orientation='vertical')
        layout.add_widget(Label(text="Resultados de las respuestas"))
        btn_next = Button(text='Continuar con más preguntas')
        btn_next.bind(on_press=self.go_next)
        layout.add_widget(btn_next)
        self.add_widget(layout)

    def go_next(self, instance):
        self.manager.current = 'additional_questions'

class AdditionalQuestions(Screen):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.layout = BoxLayout(orientation='vertical')
        self.date_picker = DatePicker()
        self.layout.add_widget(self.date_picker)
        btn_submit = Button(text='Enviar Fecha')
        btn_submit.bind(on_press=self.submit_date)
        self.layout.add_widget(btn_submit)
        self.add_widget(self.layout)

    def submit_date(self, instance):
        date = self.date_picker.get_date()
        store.put('last_period_date', answer=str(date))
        self.manager.current = 'menstrual_calendar'

class MenstrualCalendarScreen(Screen):
    def on_enter(self):
        self.display_menstrual_calendar()

    def display_menstrual_calendar(self):
        self.clear_widgets()  # Clear existing widgets

        responses = get_user_responses()
        last_period_date = responses.get('last_period_date')
        flow_duration = int(responses.get('flow_duration', 5))  # Valor por defecto si no se proporciona

        if last_period_date:
            cycles = calculate_menstrual_calendar(last_period_date, flow_duration)
            days_until_next = calculate_days_until_next_cycle(last_period_date, flow_duration)

            if cycles:
                layout = BoxLayout(orientation='vertical', padding=20, spacing=20)
                
                # Mostrar los días de la semana
                days_of_week = BoxLayout(orientation='horizontal')
                for day in ['D', 'L', 'M', 'M', 'J', 'V', 'S']:
                    days_of_week.add_widget(Label(text=day, bold=True))
                layout.add_widget(days_of_week)
                
                # Mostrar los números de los días de la semana actual
                current_date = datetime.now()
                start_of_week = current_date - timedelta(days=current_date.weekday() + 1)
                days_of_month = BoxLayout(orientation='horizontal')
                for i in range(7):
                    day_label = start_of_week + timedelta(days=i)
                    days_of_month.add_widget(Label(text=str(day_label.day)))
                layout.add_widget(days_of_month)
                
                # Mostrar días restantes para el próximo ciclo
                layout.add_widget(Label(text=f"Periodo en {days_until_next} días", font_size=24, bold=True, halign='center', valign='middle'))
                
                # Mostrar ciclos menstruales
                layout.add_widget(Label(text="Próximos Ciclos Menstruales", font_size=24, bold=True, halign='center', valign='middle'))
                for i, (start, end) in enumerate(cycles):
                    layout.add_widget(Label(text=f"Ciclo {i+1}: {start.strftime('%d/%m/%Y')} a {end.strftime('%d/%m/%Y')}", font_size=18, halign='center', valign='middle'))
                
                self.add_widget(layout)

# Administrador de pantallas
class ScreenManagement(ScreenManager):
    def __init__(self, **kwargs):
        super(ScreenManagement, self).__init__(**kwargs)
        self.add_widget(MainScreen(name='main'))
        self.add_widget(Question1(name='question1'))
        self.add_widget(Question2(name='question2'))
        self.add_widget(QuestionFlowDuration(name='question_flow_duration'))
        self.add_widget(Question3(name='question3'))
        self.add_widget(ResultsScreen(name='results'))
        self.add_widget(AdditionalQuestions(name='additional_questions'))
        self.add_widget(MenstrualCalendarScreen(name='menstrual_calendar'))
        self.check_initial_screen()

    def check_initial_screen(self):
        responses = get_user_responses()
        if 'last_period_date' in responses and 'flow_duration' in responses:
            self.current = 'menstrual_calendar'
        else:
            self.current = 'main'

# Aplicación principal
class MyApp(App):
    def build(self):
        sm = ScreenManagement()
        return sm

if __name__ == '__main__':
    MyApp().run()

