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
    AND minute <= 25;


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
SELECT id
FROM