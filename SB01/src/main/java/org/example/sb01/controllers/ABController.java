package org.example.sb01.controllers;


import lombok.AllArgsConstructor;
import org.example.sb01.entity.AuthorsBooks;
import org.example.sb01.exeptions.NoABInfo;
import org.example.sb01.models.ABModel;
import org.example.sb01.services.ABService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("ab")
public class ABController {

    private ABService abService;

    //get - запросить инфу
    @GetMapping(path = "all")
    public List<ABModel> getAllab(){
        return abService.getAllAB();
    }

    //get - запросить инфу
    @GetMapping(path = "{abID}")
    public ABModel getAB(@PathVariable("abID") Long abID){
        return abService.getAB(abID);
    }

    //post - создать инфу
    @PostMapping(path = "add")
    public ResponseEntity addAB(@RequestBody AuthorsBooks ab){
        try {
            abService.addAB(ab);
            return ResponseEntity.ok("Запись добавлена");
        }
        catch (NoABInfo e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    //put - апдейт
    @PutMapping(path = "path")
    public ResponseEntity updateAuthor(@RequestBody AuthorsBooks ab){
        try {
            abService.updateAB(ab);
            return ResponseEntity.ok("Запись успешно обновлена");
        }
        catch (NoABInfo e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    @DeleteMapping(path = "delete/{authorID}")
    public ResponseEntity deleteAuthor(@PathVariable("authorID") Long abID){
        try {
            abService.deleteAB(abID);
            return ResponseEntity.ok("Запись успешно удалена");
        }
        catch (NoABInfo e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }
}
