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
    PRIMARY KEY(id_chevalier)
};
CREATE TABLE combat {
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
CREATE SEQUENCE sq_idChevalier