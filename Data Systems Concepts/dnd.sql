create table classes
(
    class_id   integer
        primary key,
    class_name varchar(9) not null
);

create table languages
(
    language_id integer
        primary key,
    language    varchar(20) not null
);

create table races
(
    race_id   integer
        primary key,
    race_name varchar(20) not null,
    size      char(1)     not null,
    speed     int         not null,
    mod_str   char(2),
    mod_dex   char(2),
    mod_con   char(2),
    mod_int   char(2),
    mod_wis   char(2),
    mod_chr   char(2)
);

create table race_languages
(
    race_id     integer
        references races,
    language_id integer
        references languages,
    primary key (race_id, language_id)
);

create table spells
(
    spell_id      integer
        primary key,
    spell_name    varchar(128) not null,
    spell_level   int(2)       not null,
    spell_type    varchar(128) not null,
    casting_time  varchar(128) not null,
    spell_range   varchar(128) not null,
    components    varchar(128) not null,
    duration      varchar(128) not null,
    description   text         not null,
    higher_levels text         not null
);

create table class_spells
(
    class_id integer
        references classes,
    spell_id integer
        references spells,
    primary key (class_id, spell_id)
);

create table subraces
(
    subrace_id   integer
        primary key,
    subrace_name varchar(20) not null,
    race_id      integer     not null
        references races,
    mod_str      char(2),
    mod_dex      char(2),
    mod_con      char(2),
    mod_int      char(2),
    mod_wis      char(2),
    mod_chr      char(2)
);

create table traits
(
    trait_id integer
        primary key,
    trait    varchar(50) not null
);

create table race_traits
(
    race_id    integer
        references races,
    subrace_id integer
        references subraces,
    trait_id   integer
        references traits,
    primary key (race_id, trait_id)
);


