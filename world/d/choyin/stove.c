// Room: /d/choyin/stove.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��¯");
	set("long", @LONG
�������ϻ���һ�����ɵ�,�ɵ������ɺ�תΪ��ɫ.��ע�⵽¯�ź�����.
LONG
	);
         
        tell_room("d/choyin/tongbhill","ɽ�������һ������, ����������Լ���������Ŀ�����......\n"); 
        set("exits",(["out":__DIR__"tongbhill",])); 
        set("no-magic",1);
        set("objects", ([
                __DIR__"obj/tablet" :5,  
                       ]) );     
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
