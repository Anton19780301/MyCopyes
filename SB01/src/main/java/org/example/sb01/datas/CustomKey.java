package org.example.sb01.datas;


import jakarta.persistence.Column;
import jakarta.persistence.Embeddable;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/*
* возможно не понадобиться
* */

@Getter
@Setter
@Embeddable
public class CustomKey implements Serializable {

    @Column(name = "authors_id")
    Long authorsId;

    @Column(name = "books_id")
    Long booksId;

}
