
package org.example.sb01.entity;

import jakarta.persistence.*;
import lombok.*;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Entity
@Table(name = "AuthorsBooks")
public class AuthorsBooks {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    Long id;

    @ManyToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "author")
    @NonNull
    Authors authors;

    @ManyToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "book")
    Books books;

}
