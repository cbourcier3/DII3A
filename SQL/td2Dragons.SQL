/*I Modification de la base*/

CREATE TABLE comportement {
    id_comportement INTEGER NOT NULL,
    libelle VARCHAR(15),
    PRIMARY KEY (id_comportement)
};
ALTER TABLE dragon
    ADD CONSTRAINT fk_comportementDragon
    FOREIGN KEY (en_amour)
    REFERENCES comportement(id_comportement);

CREATE TABLE chevalier{
    id_chevalier INTEGER NOT NULL,
    nom VARCHAR(20),
    royaume VARCHAR(20),
    id_dragon INTEGER NOT NULL,
    id_chevalier INTEGER NOT NULL,
    vainqueur CHAR(1)
};
ALTER TABLE combat {
    ADD CONSTRAINT fk_combatDragon
    FOREIGN KEY(id_dragon)
    REFERENCES dragon(id_dragon)
    ON DELETE CASCADE
};
ALTER TABLE combat {
    ADD CONSTRAINT fk_combatChevalier
    FOREIGN KEY(id_chevalier)
    REFERENCES chevalier(id_chevalier)
    ON DELETE CASCADE
};
ALTER TABLE combat 
    ADD CONSTRAINT ck_combat_vainqueur CHECK (vainqueur IN ('C','D'));
CREATE SEQUENCE sq_idChevalier;
/* PARTIE 2 -- INTERROGATION DE LA BASE */

/* QUESTIONS 2.1*/
SELECT nom 
    FROM dragon
    WHERE crache_feu = 0;

/* QUESTIONS 2.2*/
SELECT nom 
    FROM dragon
    WHERE sexe = 'M' AND crache_feu = 0;

/* QUESTIONS 2.3*/
SELECT * 
    FROM dragon
    WHERE sexe = 'F'
    ORDER BY longueur DESC;

/*QUESTIONS 2.4*/
SELECT nom 
    FROM nourriture
    WHERE calorie < 10;

/*QUESTIONS 2.5*/
SELECT nom
    FROM dragon
    WHERE id_dragon IN
    (SELECT id_dragon 
        FROM repas
        WHERE id_nourriture IN
        (SELECT id_nourriture
            FROM nourriture 
            WHERE nom = 'oeuf')
        AND quantite > 1)
    ;

/*QUESTIONS 2.6 */ 
SELECT nom
    FROM dragon
    WHERE id_dragon IN
    (SELECT id_dragon 
        FROM repas
        WHERE id_nourriture IN
        (SELECT id_nourriture
            FROM nourriture 
            WHERE nom = 'oeuf')
        AND quantite > 1)
    AND sexe = 'F';

/*QUESTIONS 2.7*/
SELECT nom 
    FROM dragon
    WHERE sexe = 'M' AND crache_feu = 0 AND IN 
    (SELECT id_dragon 
        FROM repas
        WHERE id_nourriture IN
        (SELECT nom 
            FROM nourriture
            WHERE calorie < 10;));

/*QUESTIONS 2.8*/
SELECT n.nom, n.calorie, d.nom
    FROM nourriture n
    INNER JOIN repas r ON n.id_nourriture = r.id_nourriture
    INNER JOIN dragon d ON d.id_dragon = r.id_dragon
    WHERE d.nom = 'zmei'
    ORDER BY n.calories DESC, p.nom ASC;

/*QUESTIONS 2.9*/
SELECT nom
    FROM dragons 
    WHERE id_dragon NOT IN (
        SELECT id_dragon
            FROM repas
    );

/*QUESTIONS 2.10*/
SELECT nom 
    FROM dragons 
    WHERE id_dragon IN (
        SELECT id_dragonAimant 
            FROM amour
    );

/*QUESTIONS 2.11*/
SELECT aimant.nom, aime.nom
    FROM dragon aimant 
    INNER JOIN amour ON amour.id_dragonAimant=aimant.id_dragon
    INNER JOIN dragon aime ON aime.id_dragon=amour.id_dragonAime;

/*QUESTIONS 2.12*/
SELECT aimant.nom, aime.nom
    FROM dragon aimant 
    INNER JOIN amour ON amour.id_dragonAimant=aimant.id_dragon
    INNER JOIN dragon aime ON aime.id_dragon=amour.id_dragonAime
    WHERE amour.force='PASSIONNEMENT';

/*QUESTIONS 2.13*/
SELECT nom 
    FROM dragon
    WHERE id_dragon NOT IN (
        SELECT id_dragonAimant 
            FROM amour
);

/*QUESTIONS 2.14*/
SELECT dragonnes.nom 
    FROM dragon dragonnes 
    INNER JOIN amour ON amour.iddragonAime = dragonnes.id_dragon
    INNER JOIN dragon dragons ON dragons.id_dragon = amour.id_dragonAimant
    WHERE dragons.en_amour = 'timide' AND dragonnes.sexe ='F' AND dragons.sexe='F'

/*QUESTIONS 2.15*/
SELECT 


/*QUESTIONS 2.20*/
SELECT
FROM nourriture n
INNER JOIN repas r ON r.id_nourriture=n