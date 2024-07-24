package org.example.sb01.entity;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import org.example.sb01.datas.CustomKey;
import org.springframework.data.jpa.domain.support.AuditingEntityListener;

import java.awt.print.Book;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Entity
@Table(name = "AuthorsBooks")
public class AuthorsBooks {
    @Id
    Long id;

    @ManyToOne
    @JoinColumn(name = "author")
    Authors authors;

    @ManyToOne
    @JoinColumn(name = "book")
    Books books;

}
