#include <room.h>

inherit ROOM;

int DOOR_OPEN = 0;

void create()
{
	set("short","ʯ��");
	set("long",@LONG
����һ��ʯ�ң�������һ���������������й���͸��������˿��Կ���
ʯ���еĶ������ϱ����������ţ��������������ģ�����������
LONG
);
	set("exits",([
	"west" :__DIR__"cavehall",
	"south":__DIR__"water",
	]) );
	create_door("south","����","north",DOOR_CLOSED);
	setup();
}

