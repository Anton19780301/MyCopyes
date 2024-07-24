package org.example.sb01.repositories;

import org.example.sb01.entity.Authors;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AuthorsRepo extends JpaRepository<Authors, Long>{}
