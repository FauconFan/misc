from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        tab = data.split("\n")
        if (len(tab) == 1):
            print(">>> Single-line Comment")
        else:
            print(">>> Multi-line Comment")
        print("\n".join(tab))
    def handle_data(self, data):
        if data != "\n":
            print(">>> Data")
            print(data)
  
if __name__ == "__main__":
    html = ""       
    for i in range(int(input())):
        html += input().rstrip()
        html += '\n'

    parser = MyHTMLParser()
    parser.feed(html)
    parser.close()
