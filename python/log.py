#!/usr/bin/env python3
import logging
import os 

def doLog(logger):
    logger.debug("Debug message")
    logger.info("Info message")
    logger.warn("Warn message")
    logger.error("Error message")
    logger.critical("Critical message")

def defaultLogger():
    print("\tDefault logger")
    logging.basicConfig(level=logging.DEBUG)
    doLog(logging)

def logToFile():
    print("\tdefaultToFile")
    logFileName = "log.log"
    if os.path.isfile(logFileName):
        os.remove(logFileName)
    logger = logging.getLogger("fileLogger")
    logger.propagate = False
    logger.setLevel(logging.DEBUG)
    fh = logging.FileHandler(logFileName)
    fh.setLevel(logging.DEBUG)
    fh.setFormatter(logging.Formatter("%(asctime)s - %(levelname)s: %(message)s"))
    ch = logging.StreamHandler()
    ch.setFormatter(logging.Formatter("%(name)s: %(message)s"))
    ch.setLevel(logging.INFO)
    logger.addHandler(ch)
    logger.addHandler(fh)
    doLog(logger)

defaultLogger()
logToFile()
