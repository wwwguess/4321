// searoad.c
inherit ROOM;
void create()
{
        set("short", "ƽԭ·");
        set("long", @LONG
��������򶫣����ƽ�ƽ��·������Сʯ�ӣ��������ȥ��������Ϊ�ѽš�����
�Ե���ľԽ��Խ�٣������ƻ����������Ҹ��ط���Ϣһ�¡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"searoad",
  "west" : __DIR__"troad4",
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