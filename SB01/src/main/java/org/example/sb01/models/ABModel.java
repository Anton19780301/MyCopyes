package org.example.sb01.models;


import org.example.sb01.entity.Authors;
import org.example.sb01.entity.AuthorsBooks;
import org.example.sb01.entity.Books;

public class ABModel {
    private String name;
    private String title;

    public static ABModel toModel(AuthorsBooks ab) {
        ABModel model = new ABModel();
//        Authors authors =
//        Long authorID = ab.getAuthorsID()
//        Long book = ab.getBooksID()
        model.name = "name";
        model.title = "title";
        return model;
    }

}
