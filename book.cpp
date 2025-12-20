class Book:
    def __init__(self,title,author,book_id,total_copiec,available_copies):
        self.title = Title
        self.author = Author
        self.book_id = Book_id
        self.total_copies = Total_copies
        self.Available_copies = Available_copies

class Library:

    def __init__(self):
        self.books = {}
        self.issued_book = []
        self.returned_book = []

    def add_book(self,book_id,title,author,total_copies):
        if book_id in self.books:
            print("Book already exists!!")
            return

        self.books[book_id] = Book(title,author,book_id,total_copies)
        print("Book added successfully!!")
        
    def Search_book(self,book_id):
        if book_id not in self.books:
            print("Book not found!!")
            return

        book = self.books[book_id]
        print("Book_id : ",book.book_id)
        print("Title : ",book.title)
        print("Author : ",book.author)
        print("Total copies : ",book.total_copies)
        print("Available copies : ",book.available_copies)

    def Issuing_book(self,book_id):
        if book_id not in self.books:
            print("Book not available!!")
            return

        book = self.books[book_id]
        if book.available_copies > 0:
            book.available_copies -= 1
            self.issued_book.append(book_id)
            print("Book issued successfully!!")
        else:
            print("Book is currently unavailable!!")

    def Return_book(self,book_id):
        if book_id not in self.books:
            print("Invalid book_id!!")
            print("Enter book_id again.")
            return

        book = self.books[book_id]
        book.available_copies += 1
        self.returned_book.append(book_id)
        print("Book returned successfully!!")

    def Display_all_book(self):
        if not self.books:
            print("No book in the library yet!!")
            return
            
        print("     LIBRARY BOOKS      ")
        print("")
        for books in self.books.values():
            print("Book_id : ",books.book_id)
            print("Title : ",books.title)
            print("Author : ",books.author)
            print("Total copies : ",books.total_copies)
            print("Available copies : ",books.available_copies)

    def Library_activities(self):
        print("      LIBRARY LOG      ")
        print("")
        print("Issued books : ",self.issued_book)
        print("Returned books : ",self.returned_book)

def main():
    library = Library()

    while True:
        print("     MENU     ")
        print("")
        print("1 : Add New Book")
        print("2 : Search Book by ID")
        print("3 : Issue Book")
        print("4 : Return Book")
        print("5 : Display All Books")
        print("6 : Display Library Activities")
        print("7 : Exit Library system")

        User_choice = int(input("Enter your choice : "))

        if User_choice == 1:
            book_id = input("Enter book id")
            title = input("Enter Book title")
            author = input("Enter Book Author")
            total_copies = int(input("Enter Total copies :"))
            library.add_book(book_id,title,author,total_copies)

        elif User_choice == 2:
            book_id = input("Enter the id of the book that you want to search : ")
            library.Search_book(book_id)

        elif User_choice == 3:
            book_id = input("Enter the id of the book that you want to issue :")
            library.Issuing_book(book_id)

        elif User_choice == 4:
            book_id = input("Enter the id of the book that you want to return :")
            library.Return_book(book_id)
            
        elif User_choice == 5:
            library.Display_all_book()

        elif User_choice == 6:
            library.Library_activities()

        elif User_choice == 7:
            print("Exiting library system.....THANKS")
            break
            
        else:
             print("Invalid choice!!")

main()
