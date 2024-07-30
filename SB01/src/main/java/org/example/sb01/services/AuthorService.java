package org.example.sb01.services;

import lombok.AllArgsConstructor;
import org.example.sb01.entity.Authors;
import org.example.sb01.exeptions.NoAuthorExeption;
import org.example.sb01.models.AuthorsModel;
import org.example.sb01.repositories.AuthorsRepo;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
@AllArgsConstructor
public class AuthorService {

    private final AuthorsRepo authorRepo;

    public List<AuthorsModel> getAllAuthors(){
        List<Authors> authors = authorRepo.findAll();
        List<AuthorsModel> authorModels = new ArrayList<>();
        for (Authors author : authors) {
            authorModels.add(AuthorsModel.toModel(author));
        }
        return authorModels;
    }

    public AuthorsModel getAuthor(Long authorID){
        Authors author = authorRepo.findById(authorID).get();
        return AuthorsModel.toModel(author);
    }

    public void addAuthor(Authors author) throws NoAuthorExeption {
        if (author != null) authorRepo.save(author);
        else throw new NoAuthorExeption("Не указан автор");
    }

    public void updateAuthor(Authors author) throws NoAuthorExeption {
        Optional<Authors> authorOptional = authorRepo.findById(author.getId());
        if(authorOptional.isPresent()){
            authorRepo.save(author);
        }
        else throw new NoAuthorExeption("Не указан автор");
    }

    public void deleteAuthors(Long authorID) throws NoAuthorExeption {
        Optional<Authors> authorOptional = authorRepo.findById(authorID);
        if(authorOptional.isPresent()){
            authorRepo.deleteById(authorID);
        }
        else throw new NoAuthorExeption("Не указан автор");
    }

}
