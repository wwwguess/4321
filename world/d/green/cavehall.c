#include <room.h>

inherit ROOM;

void create()
{
	set("short","ʯ�Ҵ���");
	set("long",@LONG
����Ǵ�˵�еľ����ӵ�����֮����������һ�����񣬷��񶥲�
��һ��ҹ���鷢��ӨӨ�Ĺ�â��������ʩ���ӣ���ȴһ����Ⱦ��
LONG
);
	set("exits",([
	"south" :__DIR__"outdoor",
	]) );
        set("objects", ([
                CLASS_D("juechen")+"/master" : 1,
                ]) );

	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


