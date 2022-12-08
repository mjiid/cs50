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
  WHERE license_plate = (
    SELECT license_plate
      FROM bakery_security_logs
      WHERE hour = 10
      AND minute = 15
);


SELECT name FROM people WHERE passport_number = (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT(1)));
