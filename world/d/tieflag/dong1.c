// Room: dong1
inherit ROOM;
#include <room.h>

void create()
{
	set("short", "ɽ϶��");
	set("long", @LONG
������ɭ������ֲ�����ָ���ּ���ʪ������һ��ͨ����
��ǰ����ȥ��ȴ��֪�ж���Զ��
LONG
        );

	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"dong0",
		"west" : __DIR__"gu",
 
	]));
         
	setup();

}
  
void init()
{
	add_action("do_go","go");

}

int do_go()
{
	if(random(3)){
		this_player()->move(this_object());
		return 1;
	}

}
