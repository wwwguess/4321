// Room: /d/hhu/hhu2road1.c

inherit ROOM;
string call_mouse();

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    �����������һЩ�������ϣ�material����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"hhucross",
]));
	set("no_clean_up", 0);
        set("item_desc",([
            "material" : (: call_mouse :),
        ]));

	setup();
}
string call_mouse()
{
       call_out("find_mouse",10);
       return "���ƿ��������ϣ�ʲôҲû�з��֣�\n";
}
void find_mouse()
{
      string fileofmouse=__DIR__"npc/rat.c";
      object ob;
      tell_room(__FILE__,"ͻȻ�����������������ж�������  �شڳ�һֻ������.\n");
      ob=new(fileofmouse);
      ob->move(__FILE__);
      return;
}
