-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get a description of the crime scene at the given moment and place.
SELECT description
  FROM crime_scene_reports
    WHERE month = 7
    AND year = 2021
    AND day = 28
    AND street = "Humphrey Street";


-- Get the name of the thief who is the one that left the bakery at the time of the steal.

SELECT name
FROM people
WHERE passport_number = (
  SELECT passport_number
  FROM passengers
  WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29 ORDER BY hour, minute LIMIT(1)
    )
  );


  -- The destination where the thief escaped to

SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29 ORDER BY hour, minute LIMIT(1)
);


--
SELECT (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street";)