#include <room.h>

inherit ROOM;

void create()
{
	set("short","�ڰ�ɽ��");
	set("long",@LONG
ɽ���ܰ�������վ��ֱ���ӣ�����ż���ȵ�ʯͷ����ЩĪ������Ķ�����
�����溮���ǣ������ƺ�����ǰ�У�������һ���ڡ�
LONG
);
	set("exits",([
	"south":__DIR__"cave1",
	"north":__DIR__"mpath0",
	]) );
	setup();
	replace_program(ROOM);
}

