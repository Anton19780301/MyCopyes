package org.example.sb01.services;


import lombok.AllArgsConstructor;
import org.example.sb01.entity.Books;
import org.example.sb01.exeptions.NoBookExeption;
import org.example.sb01.models.BookModel;
import org.example.sb01.repositories.BooksRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.awt.print.Book;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
@AllArgsConstructor
public class BookService {

    private final BooksRepo bookRepo;

    public List<BookModel> getAllBooks(){
        List<Books> books = bookRepo.findAll();
        List<BookModel> bookModels = new ArrayList<>();
        for (Books book : books) {
            bookModels.add(BookModel.toModel(book));
        }
        return bookModels;
    }

    public BookModel getBook(Long bookID){
        Books book = bookRepo.findById(bookID).get();
        return BookModel.toModel(book);
    }

    public void addBook(Books book) throws NoBookExeption {
        if (book != null) bookRepo.save(book);
        else throw new NoBookExeption("Не указана книга");
    }

    public void updateBook(Books book) throws NoBookExeption {
        Optional<Books> bookOptional = bookRepo.findById(book.getId());
        if(bookOptional.isPresent()){
            bookRepo.save(book);
        }
        else throw new NoBookExeption("Не найдена книга");
    }

    public void deleteBook(Long bookID) throws NoBookExeption {
        Optional<Books> bookOptional = bookRepo.findById(bookID);
        if(bookOptional.isPresent()){
            bookRepo.deleteById(bookID);
        }
        else throw new NoBookExeption("Не найдена книга");
    }

}
