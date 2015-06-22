/* gdnet_event.h */

#ifndef GDNET_EVENT_H
#define GDNET_EVENT_H

#include "reference.h"
#include "variant.h"
#include "io/marshalls.h"

#include "enet/enet.h"

class GDNetEvent : public Reference {
	
	OBJ_TYPE(GDNetEvent,Reference);
	
public:

	enum Type {
		NONE,
		CONNECT,
		DISCONNECT,
		RECEIVE
	};

private:
	
	Type _type;
	int _peer_id;
	int _channel_id;
	ByteArray _packet;
	
protected:

	static void _bind_methods();
	
public:
	
	GDNetEvent() : _type(NONE), _peer_id(0), _channel_id(0) { }
	
	void set_event_type(Type type) { _type = type; }
	void set_peer_id(int peer_id) { _peer_id = peer_id; }
	void set_channel_id(int channel_id) { _channel_id = channel_id; }
	void set_packet(const ByteArray& packet) { _packet = packet; }
	
	Type get_event_type() { return _type; }
	int get_peer_id() { return _peer_id; }
	int get_channel_id() { return _channel_id; }
	ByteArray& get_packet() { return _packet; }
	Variant get_var();
};

#endif
