// guiyuan.c �� sbaa 11.24

inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��������¶", ({"tianxiang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�źӺ����е���������¶���ɱ�����\n");
		set("value", 500000);
	}
	setup();
}

void remove_effect(object me)
{    // object me;
    // me=this_player();

	//me->add_temp("apply/attack", - 10);
	//me->add_temp("apply/dodge", - 10);
	//me->add_temp("apply/damage", - 10);
//	me->add("bellicosity", - amount - 100);
	me->delete_temp("nodie");
      tell_object(me,"�������������¶��ҩ���������� !\n");
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,tt;   
             int aa;
        me=this_player();
      if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
       aa=me->query_temp("nodie");
if (aa) return notify_fail("��������¶һ��ֻ�ܳ�һ��!\n");
     // 	this_player()->add("bellicosity",50);
        //    	me->add_temp("apply/attack", 10);
	//me->add_temp("apply/dodge", 10);
//	me->add_temp("apply/damage", 10);
	me->set_temp("nodie", 1);
  //  me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 5);
//	me->start_call_out( (: call_other,"remove_effect", me, 10 :),1);
    call_out("remove_effect",150,me);
         tt=this_object();
         tt->move("/obj/sbaa/1");
	message_vision("$N����һ����������¶���ۣ�����Ҳ������ !\n", this_player());
		return 1;
}
