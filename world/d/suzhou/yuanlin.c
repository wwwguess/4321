//ROOM:/d/suzhou/yuanlin.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	һ�������ͥ԰���˱Ƕ����ı���һ���������ޣ�������������Ƣ
�Ļ��㣬ͥ԰���ǿ�������滨��ʯ������䣬���Ǿ������ֽ��˵ľ��Ĳ��ã���
�߻��Լ�ɿ��������ݽǣ�һ��ʯ��С��������ɽͨ�����
LONG
	);                                        
	set("exits", ([
		"north" : __DIR__"yuanlin2",  
		"east" : __DIR__"sroad2",
]));
	setup();
	replace_program(ROOM);
}
  

