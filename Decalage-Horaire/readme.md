# Projet Qt Creator : Horloge avec fenêtres multiples

## Objectif
Ce projet a pour but de créer une application Qt basée sur `QWidget` qui permet d'afficher l'heure courante et de la modifier. L'application inclut également la possibilité d'ouvrir plusieurs fenêtres d'horloges avec des décalages horaires différents.

## Fonctionnalités

1. **Fenêtre principale avec horloge réglable :**
    - Une fenêtre principale de type `QWidget` affiche l'heure courante.
    - L'utilisateur peut ajuster l'heure manuellement à l'aide de `QSpinBox` pour régler les secondes, minutes et heures.
    - Un `QTimer` est utilisé pour maintenir la mise à jour régulière de l'horloge.

2. **Création d'une horloge dans une fenêtre fille :**
    - Lors d'un clic sur le bouton "Créer une horloge", une nouvelle fenêtre fille s'ouvre.
    - Cette fenêtre affiche l'heure courante avec un décalage horaire, ainsi que la ville associée à ce décalage.

3. **Gestion des fenêtres multiples :**
    - L'utilisateur peut ouvrir plusieurs fenêtres, chacune avec un décalage horaire différent.
    - Si l'heure de la fenêtre principale (mère) est modifiée, toutes les horloges des fenêtres filles se synchronisent avec cette nouvelle heure.

## Composants utilisés
- **QWidget** : Base de la fenêtre principale.
- **QSpinBox** : Pour permettre de régler manuellement l'heure (secondes, minutes, heures).
- **QTimer** : Pour gérer la mise à jour de l'horloge en temps réel.
- **QTime** : Pour recuperer l'heure actuelle, et gerer l'affichage de l'offset
- **Fenêtre fille (QWidget)** : Affiche les horloges avec décalage horaire.
- **Signal/Slot** : Utilisé pour propager la modification de l'heure de la fenêtre mère aux fenêtres filles.

## Étapes du développement

1. **Création de la fenêtre principale :**
    - Afficher l'heure courante.
    - Ajouter les `QSpinBox` pour permettre de régler l'heure.
    - Utiliser un `QTimer` pour mettre à jour l'affichage de l'heure chaque seconde.

2. **Ajout d'une fonction de création d'horloges décalées :**
    - Créer une fonction qui permet d'ajouter des fenêtres filles via un bouton "Créer une horloge".
    - Chaque fenêtre fille affiche l'heure avec un décalage personnalisé (par exemple, Paris, Tokyo, New York).

3. **Synchronisation des fenêtres :**
    - Utiliser un mécanisme de `Signal/Slot` pour synchroniser toutes les horloges lorsqu'une modification est faite dans la fenêtre principale.
    - Toutes les fenêtres filles doivent mettre à jour leur heure en fonction du changement dans la fenêtre mère.

## Instructions d'utilisation

1. Lancer l'application.
2. La fenêtre principale affiche l'heure actuelle. Vous pouvez ajuster cette heure via les `QSpinBox`.
3. Cliquez sur le bouton "Créer une horloge" pour ouvrir une nouvelle fenêtre d'horloge avec un décalage horaire.
4. Si vous modifiez l'heure de la fenêtre principale, toutes les fenêtres filles se mettront à jour en conséquence.

## Technologies utilisées
- **Qt Creator** : Environnement de développement.
- **C++ avec Qt** : Langage et framework utilisés pour le développement de l'interface graphique et de la logique métier.

## Auteur
Ce projet a été réalisé dans le cadre de l'apprentissage de Qt et de la programmation en C++.

By hoesaek ^^
