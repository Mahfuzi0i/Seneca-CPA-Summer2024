-- Table Creation Script


--Drop all the tables once before creation to make sure there are no other tables with the same name
--drop table in order of foreign key constraint
DROP TABLE applications;
DROP TABLE interviews;
DROP TABLE offer;
DROP TABLE staff;
DROP TABLE candidates;
DROP TABLE job;
DROP TABLE employer;

/*----------------- Candidates -----------------*/
CREATE TABLE candidates(
    candidate_id integer not null PRIMARY KEY,
    firstname varchar(20) not null,
    lastname varchar(30) not null,
    dob date,
    email varchar(50) not null,
    phone varchar(20),
    address varchar(50) not null,
    city varchar(20) not null,
    province varchar(30),
    zipcode varchar(10),
    country varchar(20) not null,
    CONSTRAINT candidate_id_ck CHECK (candidate_id BETWEEN 10000 and 99999));
    
/*----------------- Employer -----------------*/
CREATE TABLE employer(
    employer_id integer not null PRIMARY KEY,
    company_name varchar(40) not null,
    contact_person varchar(50) not null,
    contact_email varchar(50) not null,
    contact_phone varchar(20),
    company_address varchar(50) not null,
    city varchar(20) not null,
    province varchar(20),
    zipcode varchar(10),
    country varchar(20) not null,
    CONSTRAINT employer_id_ck CHECK (employer_id BETWEEN 10000 and 99999));
    
/*----------------- Job -----------------*/
CREATE TABLE job(
    job_id integer not null PRIMARY KEY,
    job_title varchar(30) not null,
    job_desc varchar(200),
    location varchar(50) not null,
    salary integer,
    application_deadline date not null,
    employer_id integer not null,
    CONSTRAINT job_id_ck CHECK (job_id BETWEEN 10000 and 99999),
    CONSTRAINT employer_id_fk FOREIGN KEY (employer_id) REFERENCES employer(employer_id));
    
/*----------------- Applications -----------------*/
CREATE TABLE applications(
    application_id integer not null PRIMARY KEY,
    application_date date not null,
    status varchar(20) not null,
    notes varchar(200),
    candidate_id integer not null,
    job_id integer not null,
    CONSTRAINT application_id_ck CHECK (application_id BETWEEN 10000 and 99999),
    CONSTRAINT status_ck CHECK (status IN('Accepted', 'Rejected', 'Pending')),
    CONSTRAINT candidate_id_fk FOREIGN KEY (candidate_id) REFERENCES candidates(candidate_id),
    CONSTRAINT job_id_fk FOREIGN KEY (job_id) REFERENCES job(job_id));
    
/*----------------- Interviews -----------------*/
CREATE TABLE interviews(
    interview_id integer not null PRIMARY KEY,
    interview_date date not null,
    interview_time varchar(20) not null,
    location varchar(60) not null,
    status varchar(10),
    candidate_id integer not null,
    job_id integer not null,
    CONSTRAINT interview_id_ck CHECK (interview_id BETWEEN 10000 and 99999),
    CONSTRAINT interview_status_ck CHECK (status IN('Accepted', 'Rejected', 'Pending')),
    CONSTRAINT candidate1_id_fk FOREIGN KEY (candidate_id) REFERENCES candidates(candidate_id),
    CONSTRAINT job1_id_fk FOREIGN KEY (job_id) REFERENCES job(job_id));
    
/*----------------- Staff -----------------*/
CREATE TABLE staff(
    staff_id integer not null PRIMARY KEY,
    first_name varchar(20) not null,
    last_name varchar(30) not null,
    email varchar(50) not null,
    phone varchar(20),
    reportsto integer not null,
    CONSTRAINT staff_id_ck CHECK (staff_id BETWEEN 10000 and 99999),
    CONSTRAINT reportsto_fk FOREIGN KEY (reportsto) REFERENCES employer(employer_id));
    
/*----------------- Offer -----------------*/
CREATE TABLE offer(
    offer_id integer not null PRIMARY KEY,
    postition_title varchar(20) not null,
    employment_type varchar(20) not null,
    staff_id integer not null,
    candidate_id integer not null,
    job_id integer not null,
    CONSTRAINT offer_id_ck CHECK (offer_id BETWEEN 10000 and 99999),
    CONSTRAINT staff_id_fk FOREIGN KEY (staff_id) REFERENCES staff(staff_id),
    CONSTRAINT candidate2_id_fk FOREIGN KEY (candidate_id) REFERENCES candidates(candidate_id),
    CONSTRAINT job2_id_fk FOREIGN KEY (job_id) REFERENCES job(job_id));
    
    