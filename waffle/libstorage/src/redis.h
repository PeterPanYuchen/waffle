#ifndef REDIS_H
#define REDIS_H

#include "storage_interface.h"
#include <queue>
#include <unordered_map>
#include <cpp_redis/cpp_redis>

class redis : public storage_interface
{
public:
    redis(const std::string &host_name, int port);
    void add_server(const std::string &host_name, int port) override;
    std::string get(const std::string &key) override;
    void put(const std::string &key, const std::string &value) override;
    std::vector< std::string> get_batch(const std::vector<std::string> &keys) override;
    void put_batch(const std::vector< std::string> &keys, const std::vector<std::string> &values) override;
    void delete_batch(const std::vector< std::string> &keys) override;
    size_t get_database_size();
    bool key_exists(const std::string &key);
//    void key_list(const std::string &pattern, std::vector<std::string> &keys);
private:
    std::vector<std::shared_ptr<cpp_redis::client>> clients;
};

#endif //REDIS_H
