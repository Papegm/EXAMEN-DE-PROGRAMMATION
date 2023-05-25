from abc import ABC, abstractmethod

# Classe abstraite de base pour les patients
class Patient(ABC):
    application_name = "Gestionnaire de patients"  # Attribut de classe
    
    def __init__(self, nom, prenom, age, sexe, condition):
        self.nom = nom
        self.prenom = prenom
        self.age = age
        self.sexe = sexe
        self.condition = condition

    @abstractmethod
    def afficher_details(self):
        pass

    # Méthodes pour modifier les attributs d'instance
    def set_nom(self, nom):
        self.nom = nom

    def set_prenom(self, prenom):
        self.prenom = prenom

    def set_age(self, age):
        self.age = age

    def set_sexe(self, sexe):
        self.sexe = sexe

    def set_condition(self, condition):
        self.condition = condition

# Classe pour les patients ambulatoires
class PatientAmbulatoire(Patient):
    def __init__(self, nom, prenom, age, sexe, condition, rendez_vous):
        super().__init__(nom, prenom, age, sexe, condition)
        self.rendez_vous = rendez_vous

    def afficher_details(self):
        print(f"{self.nom} {self.prenom}, âgé de {self.age}, a un rendez-vous pour {self.condition} le {self.rendez_vous}")

    def set_rendez_vous(self, rendez_vous):
        self.rendez_vous = rendez_vous

# Classe pour les patients hospitalisés
class PatientHospitalise(Patient):
    def __init__(self, nom, prenom, age, sexe, condition, chambre):
        super().__init__(nom, prenom, age, sexe, condition)
        self.chambre = chambre

    def afficher_details(self):
        print(f"{self.nom} {self.prenom}, âgé de {self.age}, est hospitalisé pour {self.condition} dans la chambre {self.chambre}")

    def set_chambre(self, chambre):
        self.chambre = chambre

# Classe pour les patients des urgences
class PatientUrgence(Patient):
    def __init__(self, nom, prenom, age, sexe, condition, urgence):
        super().__init__(nom, prenom, age, sexe, condition)
        self.urgence = urgence

    def afficher_details(self):
        print(f"{self.nom} {self.prenom}, âgé de {self.age}, est aux urgences pour {self.condition}. Niveau d'urgence : {self.urgence}")

    def set_urgence(self, urgence):
        self.urgence = urgence
