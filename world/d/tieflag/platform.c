// searoad.c
inherit ROOM;
void create()
{
        set("short", "ƽ̨");
        set("long", @LONG
��ɽ�����ɣ�����һ��Сͤ����ʯ����������ɹۡ�һ���������ǰ����һ��
����ֱ����ۡ�
LONG
        );
        set("objects",([
        	__DIR__"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
	  	"west" : __DIR__"uproad3",
  		"eastup" : __DIR__"uproad4",
	]));
        set("outdoors", "tieflag");
        setup();
}
int valid_leave(object who,string dir)
{   
    object girl;
    girl=present("girl",this_object());
    if(girl && living(girl) && userp(who) && who->query("gender")=="����" && dir=="eastup")
   	{
   		message("vision",girl->name()+"˵��������λ��������������\n",this_object());
   		return 0; 
   	}
   	return 1;
}