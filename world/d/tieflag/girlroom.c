// Room: girl


inherit ROOM;
#include <room.h>

void create()
{
	set("short", "����");
	set("long", @LONG
���ڶ����˸�����������ʱ�ʵ�ˮ������������ɼ���������鱦......
�������������ϣ�б����һ������Ů�ӡ�
LONG
        );
         
	set("exits", ([ /* sizeof() == 2 */
  		"out" : __DIR__"goldroom",
	]));
    set("objects", ([
    	__DIR__"npc/shui": 1,
    ]) );
       

    setup();
      
}
