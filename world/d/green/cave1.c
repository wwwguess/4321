#include <room.h>

inherit ROOM;

void create()
{
	set("short","�ڰ�ɽ��");
	set("long",@LONG
ɽ���ܰ�������վ��ֱ���ӣ�����ż���ȵ�ʯͷ����ЩĪ������Ķ�����
�����溮���ǣ�������һ��ľ�ţ�������������Щ���⡣
LONG
);
	set("exits",([
	"south":__DIR__"cave0",
	"north":__DIR__"cave2",
	]) );
	create_door("south","ľ��","north",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

