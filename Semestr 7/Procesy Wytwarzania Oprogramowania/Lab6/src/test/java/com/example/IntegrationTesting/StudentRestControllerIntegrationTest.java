package com.example.IntegrationTesting;
import static org.assertj.core.api.Assertions.assertThat;
import com.example.IntegrationTesting.domain.StudentEntity;
import com.example.IntegrationTesting.repository.StudentRepository;
import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Optional;

import org.junit.jupiter.api.Test;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.hamcrest.Matchers.hasSize;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.test.context.TestPropertySource;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.http.MediaType;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.when;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.jsonPath;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;
@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT, classes = IntegrationTestingApplication.class)
@AutoConfigureMockMvc
@EnableAutoConfiguration(exclude=SecurityAutoConfiguration.class)
@TestPropertySource(locations = "classpath:application.properties")
@AutoConfigureTestDatabase
public class StudentRestControllerIntegrationTest {
    @Autowired
    private MockMvc mvc;
    @Autowired
    private StudentRepository repository;
    SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd", Locale.ENGLISH);
    @Test
    public void whenValidInput_thenCreateStudent() throws IOException, Exception {
        ObjectMapper objectMapper = new ObjectMapper();
        StudentEntity john = new StudentEntity(null, "John Smiths", formatter.parse("2001-05-05"));
        mvc.perform(post("/api/students")
                .contentType(MediaType.APPLICATION_JSON)
                .content(objectMapper.writeValueAsString(john)));
        List<StudentEntity> found = repository.findAll();
        assertThat(found).extracting(StudentEntity::getName)
                .containsOnly("John Smiths");
    }
    @Test
    public void givenStudents_whenGetStudents_thenStatus200() throws Exception {
        createTestStudent("Paul Simon",
                formatter.parse("2000-03-03"));
        createTestStudent("Axel Manhattan",
                formatter.parse("2002-02-10"));
        mvc.perform(get("/api/students")
                        .contentType(MediaType.APPLICATION_JSON))
                .andDo(print())
                .andExpect(status().isOk())
                .andExpect(content()
                        .contentTypeCompatibleWith(MediaType.APPLICATION_JSON))
                .andExpect(jsonPath("$",hasSize(greaterThanOrEqualTo(2))))
                .andExpect(jsonPath("$[0].name", is("Paul Simon")))
                .andExpect(jsonPath("$[1].name", is("Axel Manhattan")));
    }
    private void createTestStudent(String name, Date birthday) {
        StudentEntity student = new StudentEntity(null,name,birthday);
        repository.saveAndFlush(student);
    }

    @Test
    public void whenGetStudentById_thenGetStudent() throws Exception {
        createTestStudent("Paul Simon", formatter.parse("2000-03-03"));

        mvc.perform(get("/api/students/{id}", 1)
                        .contentType(MediaType.APPLICATION_JSON))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name", is("Paul Simon")));
    }

    @Test
    public void whenGetStudentByName_thenGetStudent() throws Exception {
        String name = "John Smiths";
        createTestStudent(name, formatter.parse("2000-03-03"));
        mvc.perform(get("/api/students/name/{name}", name)
                        .contentType(MediaType.APPLICATION_JSON))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name", is(name)));
    }
}