#!/bin/bash

mvn clean
mvn package

echo applying execute permissions...
chmod +x target/jogl-minimum-0.0.1-SNAPSHOT.jar

echo executing...
java -jar target/jogl-minimum-0.0.1-SNAPSHOT.jar