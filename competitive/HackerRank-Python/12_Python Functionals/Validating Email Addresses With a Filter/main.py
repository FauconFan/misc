def fun(s):
    try:
        username, mail = s.split("@")
        site, extension = mail.split(".")
    except ValueError:
        return False
    
    if username.replace("-", "").replace("_", "").isalnum() == False:
        return False
    elif site.isalnum() == False:
        return False
    elif len(extension) > 3:
        return False
    return True