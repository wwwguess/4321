#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"������"NOR);
	set("long", @LONG
�����ǳ�͢�Ӵ����ʱ�ں����������λ���Ŀ��˵ı��ݡ�����
�����ʩ�����Ȼʹ��ﻹҪ������������������Ķ�����Ǯ�ˣ���
��Щ������װ�ַ��ġ�һ�����Ž����Ĺ�Ա��ӭ�����ķ����͡�
LONG         
	);

	set("exits", ([ 
 "east" :__DIR__"ndj2",
 	])); 
         set("objects", ([
  __DIR__"npc/mkbl" : 1,
]));
	setup();
	
}

