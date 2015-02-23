
CREATE DATABASE dao
  WITH OWNER = postgres
       ENCODING = 'UTF8'
       TABLESPACE = pg_default
       LC_COLLATE = 'en_US.UTF-8'
       LC_CTYPE = 'en_US.UTF-8'
       CONNECTION LIMIT = -1;

CREATE TABLE test
(
  id serial NOT NULL,
  int1 integer,
  int2 integer,
  CONSTRAINT test_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE test
  OWNER TO postgres;
