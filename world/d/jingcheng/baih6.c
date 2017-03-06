// Room : "/d/jingcheng/baih6.c"
// Made by ysgl (1997.10.23)

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�׻����"NOR);
	set("long", @LONG
  �����ǰ׻���ֵ��϶��ˣ������ǰ׻���ֺ���ȸ��ֵ�ʮ
��·�ڣ����洫������˿�����ͻ�Ц�������������������
�ġ������ַ�",������һ��ˮ����, ������һ����լ�ӣ���˵˭Ҳû�������浽
��ס��ʲô�ˣ�ֻ�����������������������İ��Ҳ���ҵ���
����Ұ��
LONG         
	);

	set("exits", ([ 
		"north" :__DIR__"baih5",
		"east" :__DIR__"cayfang",   
		"west" :__DIR__"shuiguod",
	]));    

	set("outdoors", "city");
	setup();
}
                
void init()
{	
	add_action("do_play", "play");
}

int do_play(string arg)
{
	object me, ob, obj, jiaren;
	me = this_object();
	ob = this_player();
                           
	if( !(obj=present("baiyu pipa", ob)) )
		return 0;  
	if( !arg || (arg != "pipa" && arg !="����" && arg != "��������") )                   
		return notify_fail("��Ҫ��ʲô��\n");
	if( ob->query_temp("ask_pipa") ) 
		return notify_fail("������������㵯ʲô����\n");
	if( ob->query_skill("music", 1) < 30 )
		return notify_fail("�������������̫�����ˣ����ǸϿ��ס�������˺����߰ɡ�\n");
	jiaren = new(__DIR__"npc/jiaren");
	jiaren->move(me);
	message_vision("ֻ�������ϵ��š�֨ѽ��һ�����ˣ��߳�һ�����¼�������\n");
	tell_object(ob,GRN"���¼��˹������˵��"+RANK_D->query_respect(ob)+
	"���Ǻü��գ��Ҽ����˶Դ�ʮ�����\n"
	"���������������������һ����\n"NOR);
	ob->set_temp("enter", 1);
	me->set("exits/south", __DIR__"baih7");
	remove_call_out("close");
	call_out("close", 5, me, ob);
	return 1;
}                              

int valid_leave(object ob, string dir)
{
	if( !ob->query_temp("enter") && dir == "south" ) 
		return notify_fail("���¼���������ס��˵���Ҽ����˲�δ�����㣬���˻�����ذɡ�\n");
	tell_object(ob,GRN"���¼������Ժһ���ֵ�����������롣\n"NOR);
	return ::valid_leave(ob, dir);                 
}                                

void close(object me, object ob)
{
	message_vision("ָ�������顱��һ�������¼����߽���Ժ�����Ź����ˡ�\n");
	me->delete("exits/south"); 
	destruct(ob);
}