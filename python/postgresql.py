#!/usr/bin/env python3

import psycopg2
from faker import Faker
import random

USERS = 10

def populate(cur, conn):
    conn.autocommit = True
    cur.execute("drop table if exists users")
    cur.execute("drop table if exists addresses")
    conn.autocommit = False
    fake = Faker()
    def populate_users(cur, con):
        cur.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id serial,
        name  varchar,
        dob DATE,
        primary key(id))
        """)
        con.commit()
        for _ in range(USERS):
            cursor.execute(f"""
            INSERT INTO users(name, dob) VALUES('{fake.name()}', '{fake.date_of_birth()}')
            """)
        conn.commit()
    def populate_addresses(cur, con):
        cur.execute("""
    CREATE TABLE IF NOT EXISTS addresses(
        id int,
        address varchar)
        """)
        conn.commit()
        fake = Faker()
        for i in range(USERS - 1):
            cursor.execute(f"""
            INSERT INTO addresses(id, address) VALUES('{i+1}', '{fake.address()}')
            """)
        # some users have more than one address
        for _ in range(3):
            cursor.execute(f"""
            INSERT INTO addresses(id, address) VALUES('{random.randint(1, USERS - 1)}', '{fake.address()}')
            """)
    populate_users(cur, conn)
    populate_addresses(cur, conn)


def printrecords(f):
    def wrapper(cursor):
        f(cursor)
        for i in cursor:
            print(i)
        print()
    return wrapper
        
    
@printrecords
def fetch(cursor):
    cursor.execute("""
    SELECT users.id, users.name, addresses.address  FROM users
    inner join addresses
    on users.id  = addresses.id
    order by users.id
    """)

@printrecords
def fetchjoin(cursor):
    cursor.execute("""
    SELECT users.id, users.name, addresses.address  FROM users
    left join addresses
    on users.id  = addresses.id
    order by users.id
    """)

@printrecords
def homeless(cursor):
    cursor.execute("""
    SELECT users.id, users.name FROM users
    where (select count(id) from  addresses where id = users.id) = 0
    """)
            
with psycopg2.connect(user = "dima",
                      database = "dima") as connection:
    with connection.cursor() as cursor:
        populate(cursor, connection)
        fetch(cursor)
        fetchjoin(cursor)
        homeless(cursor)
