
from copy import deepcopy

from src.logger import logdijunction, logdijunctionValue, logdijunctionend, logdijunctionMessage
from src.Exceptions import IncoherenceException


def disjonction(env, is_poor):
	k = env.getNextUndefined()
	if k is None:
		return
	logdijunction(env, k)
	envTrue = deepcopy(env)
	envFalse = deepcopy(env)
	envTrue.setEnv(k, True)
	envFalse.setEnv(k, False)
	is_ok_true = True
	is_ok_false = True
	try:
		logdijunctionValue(envTrue, k, True)
		algo(envTrue, is_poor)
	except IncoherenceException:
		logdijunctionMessage("We found an inconsistency when %s is True" % k)
		is_ok_true = False
	try:
		logdijunctionValue(envFalse, k, False)
		algo(envFalse, is_poor)
	except IncoherenceException:
		logdijunctionMessage("We found an inconsistency when %s is False" % k)
		is_ok_false = False
	if is_ok_true and is_ok_false:
		env.fusionUnionForDisjonction(envTrue, envFalse)
		msg = "We take common values in both environments"
		msgVerbose = envTrue.StrTableOfTruth() + "\n" + envFalse.StrTableOfTruth()
		logdijunctionMessage(msg, msgVerbose=msgVerbose)
	elif is_ok_true:
		env.setEnv(k, True)
		msg = "We have an inconsistency when %s is false, so it's true" % k
		msgVerbose = env.StrTableOfTruth()
		logdijunctionMessage(msg, msgVerbose=msgVerbose)
	elif is_ok_false:
		env.setEnv(k, False)
		msg = "We have an inconsistency when %s is true, so it's false" % k
		msgVerbose = env.StrTableOfTruth()
		logdijunctionMessage(msg, msgVerbose=msgVerbose)
	else:
		msg = "We have an inconsistency when value is True or False, it results to an error"
		logdijunctionMessage(msg)
		raise IncoherenceException
	logdijunctionend()


def algo(env, is_poor):
	is_rich = not is_poor
	while True:
		copy = deepcopy(env)
		env.applyRules()
		if copy == env and is_rich:
			disjonction(env, is_poor)
		if copy == env or (not env.stillHaveUndefined() and is_rich):
			break
