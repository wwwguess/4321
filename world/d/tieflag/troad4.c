// searoad.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������������������������б��·���ԵĹ�ľ����������ľ��Խ�ߵ���Խ������
������ȥ��ȻҪ�ߵ������ȥ�ˡ��ϱ���һ��ͨ��ɽ�ϵ�С·��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"troad2",
  "south" : __DIR__"road",	
  "east" : __DIR__"plain",
]));
        set("outdoors", "tieflag");
        setup();
}


int valid_leave(object who,string dir)
{
   	if(userp(who) && random(3))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}
