package org.example.sb01.entity;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.Set;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Entity
@Table(name = "Authors")
public class Authors {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    Long id;

    @Column(name = "authors")
    String name;

    @OneToMany(cascade = CascadeType.ALL, mappedBy = "authors")
    Set<AuthorsBooks> authors;

    public Authors(String name) {
        this.name = name;
    }

}
