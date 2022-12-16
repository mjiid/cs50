-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get a description of the crime scene at the given moment and place.
SELECT description
  FROM crime_scene_reports
    WHERE month = 7
    AND year = 2021
    AND day = 28
    AND street = "Humphrey Street";

-- Get the the response of the intreviewed people:
SELECT transcript
FROM interviews
  WHERE year = 2021
  AND month = 7
  AND day = 28;

-- Cars the left the bakery parking lot:
SELECT license_plate
FROM bakery_security_logs
  WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute <= 25
    AND activity = "exit";


-- Get the cars owner:
SELECT name
FROM people
  WHERE license_plate
  IN (
      SELECT license_plate
      FROM bakery_security_logs
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND hour = 10
          AND minute <= 25
          AND activity = "exit"
  );


-- Get the names of people who withdrawed money on the ATM of leggett street.
SELECT name
FROM people
WHERE id IN (
  SELECT person_id
  FROM bank_accounts
  WHERE account_number
  IN (
    SELECT account_number
    FROM atm_transactions
      WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
  ));



-- Get every caller name:
SELECT name
FROM people
WHERE phone_number
IN (
  SELECT caller
  FROM phone_calls
  WHERE year = 2021
  AND month = 7
  AND day = 28
  AND duration < 60
);



-- get the earliest flights:
select name
From people
where passport_number IN
(select passport_number
FROM passengers
where flight_id IN
(select id
from flights
where day = 29
and month = 7
and year = 2021
and origin_airport_id = (
  select id
  from airports
  where city = "Fiftyville"
  )
  Order by hour, minute Limit(1)));



  -- the thief is the intersection of all the names lists selected above i.e:

SELECT name
FROM people
  WHERE license_plate
  IN (
      SELECT license_plate
      FROM bakery_security_logs
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND hour = 10
          AND minute <= 25
          AND activity = "exit"
  )
  INTERSECT
SELECT name
FROM people
WHERE id IN (
  SELECT person_id
  FROM bank_accounts
  WHERE account_number
  IN (
    SELECT account_number
    FROM atm_transactions
      WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
  ))
  INTERSECT
SELECT name
FROM people
WHERE phone_number
IN (
  SELECT caller
  FROM phone_calls
  WHERE year = 2021
  AND month = 7
  AND day = 28
  AND duration < 60
)
INTERSECT
select name
From people
where passport_number IN
(select passport_number
FROM passengers
where flight_id IN
(select id
from flights
where day = 29
and month = 7
and year = 2021
and origin_airport_id = (
  select id
  from airports
  where city = "Fiftyville"
  )
  Order by hour, minute Limit(1)));


-- Get the city the thief escaped to:

SELECT city
FROM airports
WHERE id IN
(
SELECT destination_airport_id
FROM flights
WHERE id IN(
  SELECT flight_id
  FROM passengers
  WHERE passport_number
  IN (
    SELECT passport_number
    FROM people
    WHERE name = "Bruce")));

-- Get the person who helped the thief escape:

SELECT name
FROM people
 WHERE phone_number = (
  SELECT receiver
  FROM phone_calls
  WHERE caller = (
    SELECT phone_number
    FROM people
    WHERE name = "Bruce")
    AND year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60);