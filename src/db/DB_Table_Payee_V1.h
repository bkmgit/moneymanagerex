﻿// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013 - 2022 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017 - 2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022 Mark Whalley (mark@ipx.co.uk)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2022-10-16 12:50:22.607317.
 *          DO NOT EDIT!
 */
//=============================================================================
#pragma once

#include "DB_Table.h"

struct DB_Table_PAYEE_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_PAYEE_V1 Self;

    /** A container to hold list of Data records for the table*/
    struct Data_Set : public std::vector<Self::Data>
    {
        /**Return the data records as a json array string */
        wxString to_json() const
        {
            StringBuffer json_buffer;
            PrettyWriter<StringBuffer> json_writer(json_buffer);

            json_writer.StartArray();
            for (const auto & item: *this)
            {
                json_writer.StartObject();
                item.as_json(json_writer);
                json_writer.EndObject();
            }
            json_writer.EndArray();

            return json_buffer.GetString();
        }
    };

    /** A container to hold a list of Data record pointers for the table in memory*/
    typedef std::vector<Self::Data*> Cache;
    typedef std::map<int, Self::Data*> Index_By_Id;
    Cache cache_;
    Index_By_Id index_by_id_;
    Data* fake_; // in case the entity not found

    /** Destructor: clears any data records stored in memory */
    ~DB_Table_PAYEE_V1() 
    {
        delete this->fake_;
        destroy_cache();
    }
     
    /** Removes all records stored in memory (cache) for the table*/ 
    void destroy_cache()
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fn(&Data::destroy));
        cache_.clear();
        index_by_id_.clear(); // no memory release since it just stores pointer and the according objects are in cache
    }

    /** Creates the database table if the table does not exist*/
    bool ensure(wxSQLite3Database* db)
    {
        if (!exists(db))
        {
            try
            {
                db->ExecuteUpdate("CREATE TABLE PAYEE_V1(PAYEEID integer primary key, PAYEENAME TEXT COLLATE NOCASE NOT NULL UNIQUE, CATEGID integer, SUBCATEGID integer, NUMBER TEXT, WEBSITE TEXT, NOTES TEXT, ACTIVE integer)");
                this->ensure_data(db);
            }
            catch(const wxSQLite3Exception &e) 
            { 
                wxLogError("PAYEE_V1: Exception %s", e.GetMessage().utf8_str());
                return false;
            }
        }

        this->ensure_index(db);

        return true;
    }

    bool ensure_index(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_PAYEE_INFONAME ON PAYEE_V1(PAYEENAME)");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("PAYEE_V1: Exception %s", e.GetMessage().utf8_str());
            return false;
        }

        return true;
    }

    void ensure_data(wxSQLite3Database* db)
    {
        db->Begin();
        db->Commit();
    }
    
    struct PAYEEID : public DB_Column<int>
    { 
        static wxString name() { return "PAYEEID"; } 
        explicit PAYEEID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    
    struct PAYEENAME : public DB_Column<wxString>
    { 
        static wxString name() { return "PAYEENAME"; } 
        explicit PAYEENAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct CATEGID : public DB_Column<int>
    { 
        static wxString name() { return "CATEGID"; } 
        explicit CATEGID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    
    struct SUBCATEGID : public DB_Column<int>
    { 
        static wxString name() { return "SUBCATEGID"; } 
        explicit SUBCATEGID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    
    struct NUMBER : public DB_Column<wxString>
    { 
        static wxString name() { return "NUMBER"; } 
        explicit NUMBER(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct WEBSITE : public DB_Column<wxString>
    { 
        static wxString name() { return "WEBSITE"; } 
        explicit WEBSITE(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct NOTES : public DB_Column<wxString>
    { 
        static wxString name() { return "NOTES"; } 
        explicit NOTES(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct ACTIVE : public DB_Column<int>
    { 
        static wxString name() { return "ACTIVE"; } 
        explicit ACTIVE(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    
    typedef PAYEEID PRIMARY;
    enum COLUMN
    {
        COL_PAYEEID = 0
        , COL_PAYEENAME = 1
        , COL_CATEGID = 2
        , COL_SUBCATEGID = 3
        , COL_NUMBER = 4
        , COL_WEBSITE = 5
        , COL_NOTES = 6
        , COL_ACTIVE = 7
    };

    /** Returns the column name as a string*/
    static wxString column_to_name(COLUMN col)
    {
        switch(col)
        {
            case COL_PAYEEID: return "PAYEEID";
            case COL_PAYEENAME: return "PAYEENAME";
            case COL_CATEGID: return "CATEGID";
            case COL_SUBCATEGID: return "SUBCATEGID";
            case COL_NUMBER: return "NUMBER";
            case COL_WEBSITE: return "WEBSITE";
            case COL_NOTES: return "NOTES";
            case COL_ACTIVE: return "ACTIVE";
            default: break;
        }
        
        return "UNKNOWN";
    }

    /** Returns the column number from the given column name*/
    static COLUMN name_to_column(const wxString& name)
    {
        if ("PAYEEID" == name) return COL_PAYEEID;
        else if ("PAYEENAME" == name) return COL_PAYEENAME;
        else if ("CATEGID" == name) return COL_CATEGID;
        else if ("SUBCATEGID" == name) return COL_SUBCATEGID;
        else if ("NUMBER" == name) return COL_NUMBER;
        else if ("WEBSITE" == name) return COL_WEBSITE;
        else if ("NOTES" == name) return COL_NOTES;
        else if ("ACTIVE" == name) return COL_ACTIVE;

        return COLUMN(-1);
    }
    
    /** Data is a single record in the database table*/
    struct Data
    {
        friend struct DB_Table_PAYEE_V1;
        /** This is a instance pointer to itself in memory. */
        Self* table_;
    
        int PAYEEID;//  primary key
        wxString PAYEENAME;
        int CATEGID;
        int SUBCATEGID;
        wxString NUMBER;
        wxString WEBSITE;
        wxString NOTES;
        int ACTIVE;

        int id() const
        {
            return PAYEEID;
        }

        void id(int id)
        {
            PAYEEID = id;
        }

        bool operator < (const Data& r) const
        {
            return this->id() < r.id();
        }
        
        bool operator < (const Data* r) const
        {
            return this->id() < r->id();
        }

        explicit Data(Self* table = 0) 
        {
            table_ = table;
        
            PAYEEID = -1;
            CATEGID = -1;
            SUBCATEGID = -1;
            ACTIVE = -1;
        }

        explicit Data(wxSQLite3ResultSet& q, Self* table = 0)
        {
            table_ = table;
        
            PAYEEID = q.GetInt(0); // PAYEEID
            PAYEENAME = q.GetString(1); // PAYEENAME
            CATEGID = q.GetInt(2); // CATEGID
            SUBCATEGID = q.GetInt(3); // SUBCATEGID
            NUMBER = q.GetString(4); // NUMBER
            WEBSITE = q.GetString(5); // WEBSITE
            NOTES = q.GetString(6); // NOTES
            ACTIVE = q.GetInt(7); // ACTIVE
        }

        Data& operator=(const Data& other)
        {
            if (this == &other) return *this;

            PAYEEID = other.PAYEEID;
            PAYEENAME = other.PAYEENAME;
            CATEGID = other.CATEGID;
            SUBCATEGID = other.SUBCATEGID;
            NUMBER = other.NUMBER;
            WEBSITE = other.WEBSITE;
            NOTES = other.NOTES;
            ACTIVE = other.ACTIVE;
            return *this;
        }

        template<typename C>
        bool match(const C &c) const
        {
            return false;
        }

        bool match(const Self::PAYEEID &in) const
        {
            return this->PAYEEID == in.v_;
        }

        bool match(const Self::PAYEENAME &in) const
        {
            return this->PAYEENAME.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::CATEGID &in) const
        {
            return this->CATEGID == in.v_;
        }

        bool match(const Self::SUBCATEGID &in) const
        {
            return this->SUBCATEGID == in.v_;
        }

        bool match(const Self::NUMBER &in) const
        {
            return this->NUMBER.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::WEBSITE &in) const
        {
            return this->WEBSITE.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::NOTES &in) const
        {
            return this->NOTES.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::ACTIVE &in) const
        {
            return this->ACTIVE == in.v_;
        }

        // Return the data record as a json string
        wxString to_json() const
        {
            StringBuffer json_buffer;
            PrettyWriter<StringBuffer> json_writer(json_buffer);

			json_writer.StartObject();			
			this->as_json(json_writer);
            json_writer.EndObject();

            return json_buffer.GetString();
        }

        // Add the field data as json key:value pairs
        void as_json(PrettyWriter<StringBuffer>& json_writer) const
        {
            json_writer.Key("PAYEEID");
            json_writer.Int(this->PAYEEID);
            json_writer.Key("PAYEENAME");
            json_writer.String(this->PAYEENAME.utf8_str());
            json_writer.Key("CATEGID");
            json_writer.Int(this->CATEGID);
            json_writer.Key("SUBCATEGID");
            json_writer.Int(this->SUBCATEGID);
            json_writer.Key("NUMBER");
            json_writer.String(this->NUMBER.utf8_str());
            json_writer.Key("WEBSITE");
            json_writer.String(this->WEBSITE.utf8_str());
            json_writer.Key("NOTES");
            json_writer.String(this->NOTES.utf8_str());
            json_writer.Key("ACTIVE");
            json_writer.Int(this->ACTIVE);
        }

        row_t to_row_t() const
        {
            row_t row;
            row(L"PAYEEID") = PAYEEID;
            row(L"PAYEENAME") = PAYEENAME;
            row(L"CATEGID") = CATEGID;
            row(L"SUBCATEGID") = SUBCATEGID;
            row(L"NUMBER") = NUMBER;
            row(L"WEBSITE") = WEBSITE;
            row(L"NOTES") = NOTES;
            row(L"ACTIVE") = ACTIVE;
            return row;
        }

        void to_template(html_template& t) const
        {
            t(L"PAYEEID") = PAYEEID;
            t(L"PAYEENAME") = PAYEENAME;
            t(L"CATEGID") = CATEGID;
            t(L"SUBCATEGID") = SUBCATEGID;
            t(L"NUMBER") = NUMBER;
            t(L"WEBSITE") = WEBSITE;
            t(L"NOTES") = NOTES;
            t(L"ACTIVE") = ACTIVE;
        }

        /** Save the record instance in memory to the database. */
        bool save(wxSQLite3Database* db)
        {
            if (db && db->IsReadOnly()) return false;
            if (!table_ || !db) 
            {
                wxLogError("can not save PAYEE_V1");
                return false;
            }

            return table_->save(this, db);
        }

        /** Remove the record instance from memory and the database. */
        bool remove(wxSQLite3Database* db)
        {
            if (!table_ || !db) 
            {
                wxLogError("can not remove PAYEE_V1");
                return false;
            }
            
            return table_->remove(this, db);
        }

        void destroy()
        {
            delete this;
        }
    };

    enum
    {
        NUM_COLUMNS = 8
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    /** Name of the table*/    
    wxString name() const { return "PAYEE_V1"; }

    DB_Table_PAYEE_V1() : fake_(new Data())
    {
        query_ = "SELECT PAYEEID, PAYEENAME, CATEGID, SUBCATEGID, NUMBER, WEBSITE, NOTES, ACTIVE FROM PAYEE_V1 ";
    }

    /** Create a new Data record and add to memory table (cache)*/
    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    
    /** Create a copy of the Data record and add to memory table (cache)*/
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    /**
    * Saves the Data record to the database table.
    * Either create a new record or update the existing record.
    * Remove old record from the memory table (cache)
    */
    bool save(Self::Data* entity, wxSQLite3Database* db)
    {
        wxString sql = wxEmptyString;
        if (entity->id() <= 0) //  new & insert
        {
            sql = "INSERT INTO PAYEE_V1(PAYEENAME, CATEGID, SUBCATEGID, NUMBER, WEBSITE, NOTES, ACTIVE) VALUES(?, ?, ?, ?, ?, ?, ?)";
        }
        else
        {
            sql = "UPDATE PAYEE_V1 SET PAYEENAME = ?, CATEGID = ?, SUBCATEGID = ?, NUMBER = ?, WEBSITE = ?, NOTES = ?, ACTIVE = ? WHERE PAYEEID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->PAYEENAME);
            stmt.Bind(2, entity->CATEGID);
            stmt.Bind(3, entity->SUBCATEGID);
            stmt.Bind(4, entity->NUMBER);
            stmt.Bind(5, entity->WEBSITE);
            stmt.Bind(6, entity->NOTES);
            stmt.Bind(7, entity->ACTIVE);
            if (entity->id() > 0)
                stmt.Bind(8, entity->PAYEEID);

            stmt.ExecuteUpdate();
            stmt.Finalize();

            if (entity->id() > 0) // existent
            {
                for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
                {
                    Self::Data* e = *it;
                    if (e->id() == entity->id()) 
                        *e = *entity;  // in-place update
                }
            }
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("PAYEE_V1: Exception %s, %s", e.GetMessage().utf8_str(), entity->to_json());
            return false;
        }

        if (entity->id() <= 0)
        {
            entity->id((db->GetLastRowId()).ToLong());
            index_by_id_.insert(std::make_pair(entity->id(), entity));
        }
        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(int id, wxSQLite3Database* db)
    {
        if (id <= 0) return false;
        try
        {
            wxString sql = "DELETE FROM PAYEE_V1 WHERE PAYEEID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                {
                    index_by_id_.erase(entity->id());
                    delete entity;
                }
                else 
                {
                    c.push_back(entity);
                }
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("PAYEE_V1: Exception %s", e.GetMessage().utf8_str());
            return false;
        }

        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    template<typename... Args>
    Self::Data* get_one(const Args& ... args)
    {
        for (Index_By_Id::iterator it = index_by_id_.begin(); it != index_by_id_.end(); ++ it)
        {
            Self::Data* item = it->second;
            if (item->id() > 0 && match(item, args...)) 
            {
                ++ hit_;
                return item;
            }
        }

        ++ miss_;

        return 0;
    }
    
    /**
    * Search the memory table (Cache) for the data record.
    * If not found in memory, search the database and update the cache.
    */
    Self::Data* get(int id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return 0;
        }

        Index_By_Id::iterator it = index_by_id_.find(id);
        if (it != index_by_id_.end())
        {
            ++ hit_;
            return it->second;
        }
        
        ++ miss_;
        Self::Data* entity = 0;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().utf8_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
                index_by_id_.insert(std::make_pair(id, entity));
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().utf8_str(), e.GetMessage().utf8_str());
        }
        
        if (!entity) 
        {
            entity = this->fake_;
            // wxLogError("%s: %d not found", this->name().utf8_str(), id);
        }
 
        return entity;
    }

    /**
    * Return a list of Data records (Data_Set) derived directly from the database.
    * The Data_Set is sorted based on the column number.
    */
    const Data_Set all(wxSQLite3Database* db, COLUMN col = COLUMN(0), bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(col == COLUMN(0) ? this->query() : this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC "));

            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(std::move(entity));
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().utf8_str(), e.GetMessage().utf8_str());
        }

        return result;
    }
};

