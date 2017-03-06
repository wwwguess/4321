// ROOM:__DIR__"canyon4"

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","�����е�");
	set("long",@LONG                                   
������������Ʊ������ط�������࣬��������Ϊ����Ϊ��Ӫ���ͨ
���Ϊ���õ�ԭ���Ϸ�һʮ��·�ĵط����Ǿ��ǹؿڣ����չص���ڣ�
�����ߵ�ɽ���ƺ�����ƽ������̫��Ȼ�����������ʲô����Ҳ˵������
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==3 */
        	"north" : __DIR__"canyon3",
        	"south" : __DIR__"canyon5",
        	"east" : __DIR__"camp1",
	]) ); //eof(exits)
	
	setup();
	
} //EOF

void init()
{
	add_action("do_swear","swear");
} //eof(init)

int do_swear(string arg)
{
	object me;

	me=this_player();
	
	if (!this_player()->query_temp("��Ӫ/swear") ) return 0;
	
	if (!arg) return notify_fail("���ͻȻһ������:��Ҫ��������\n");
	
	if (arg != "�Ұ�����ϯ���ض�" && arg != "�Ұ���������II")
		return notify_fail("���ͻȻһ������:��Ҫ��������\n");
		
	this_player()->set_temp("��Ӫ/swear", 0);
	
    	message_vision(HIB"ͻȻ��һ��ǿ�⽫"HIW"$N"HIB"����ס��\n"NOR,me);
    	message_vision(HIW"��¡������������������������������������\n"NOR,me);
    	message_vision(HIW"������������¡������������¡������������\n"NOR,me);
    	message_vision(HIW"����������������¡������������������¡��\n"NOR,me);
    	message_vision(HIC"$N"HIW"�ҽ���һ��:�ۣ���ʹ��������������\n"NOR,me);
    	message_vision(HIW"����������������������������������������\n"NOR,me);
    	message_vision(HIW"����������������������������������������\n"NOR,me);
    	message_vision(HIW"����������������������������������������\n"NOR,me);
    	message_vision(HIW"����������������������������������������\n"NOR,me);
    	message_vision(HIW"����������������������������������������\n"NOR,me);
    
    	tell_room(__DIR__"blackmarket",me->name()+"�����͹����ˡ�\n");
    	tell_room(environment(me),me->name()+"ͻȻ����ʧ��\n",me);
    	this_player()->move(__DIR__"blackmarket");
    	return 1;

} // EOF

