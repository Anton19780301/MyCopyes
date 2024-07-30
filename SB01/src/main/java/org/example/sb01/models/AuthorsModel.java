package org.example.sb01.models;

import org.example.sb01.entity.Authors;

public class AuthorsModel {
    private String name;

    public static AuthorsModel toModel(Authors author) {
        AuthorsModel model = new AuthorsModel();
        model.name = author.getName();
        return model;
    }




}
