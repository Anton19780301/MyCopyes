package org.example.sb01.services;

import lombok.AllArgsConstructor;
import org.example.sb01.entity.AuthorsBooks;
import org.example.sb01.exeptions.NoABInfo;
import org.example.sb01.models.ABModel;
import org.example.sb01.repositories.ABRepo;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
@AllArgsConstructor

public class ABService {
    private final ABRepo abRepo;

    public List<ABModel> getAllAB(){
        List<AuthorsBooks> listAB = abRepo.findAll();
        List<ABModel> abModels = new ArrayList<>();
        for (AuthorsBooks ab : listAB) {
            abModels.add(ABModel.toModel(ab));
        }
        System.out.println(abModels);
        return abModels;
    }

    public ABModel getAB(Long abID){
        AuthorsBooks ab = abRepo.findById(abID).get();
        return ABModel.toModel(ab);
    }

    public void addAB(AuthorsBooks ab) throws NoABInfo {
        if (ab != null) abRepo.save(ab);
        else throw new NoABInfo("Не найдена запись");
    }

    public void updateAB(AuthorsBooks ab) throws NoABInfo {
        Optional<AuthorsBooks> abOptional = abRepo.findById(ab.getId());
        if(abOptional.isPresent()){
            abRepo.save(ab);
        }
        else throw new NoABInfo("Не найдена запись");
    }

    public void deleteAB(Long abID) throws NoABInfo {
        Optional<AuthorsBooks> abOptional = abRepo.findById(abID);
        if(abOptional.isPresent()){
            abRepo.deleteById(abID);
        }
        else throw new NoABInfo("Не найдена запись");
    }

}
