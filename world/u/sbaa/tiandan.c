// guiyuan.c �� sbaa 11.15

inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��ħ��", ({"tianmo dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�źӺ����е���ħ��������߹���������ɱ����\n");
		set("value", 200000);
	}
	setup();
}

void remove_effect(object me)
{    // object me;
    // me=this_player();
  	me->add_temp("apply/attack", - 10);
	me->add_temp("apply/dodge", - 10);
	me->add_temp("apply/damage", - 10);
//	me->add("bellicosity", - amount - 100);
	me->delete_temp("powerup");
      tell_object(me,"�������ħ����ҩ���������� !\n");
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,tt;   
             int aa=0;
        me=this_player();
      if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
       aa=me->query_temp("powerup");
     if (aa>1) { 
        tell_object(me,"��ħ���Ե�̫����!\n");
        me->add("kee",-200);
        return 1;
      }
      this_player()->add("bellicosity",50);
       	me->add_temp("apply/attack", 10);
	me->add_temp("apply/dodge", 10);
	me->add_temp("apply/damage", 10);
        aa=aa+1;
	me->set_temp("powerup", aa);
  //  me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 5);
//	me->start_call_out( (: call_other,"remove_effect", me, 10 :),1);
        call_out("remove_effect",150,me);
        tt=this_object();
        tt->move("/u/sbaa/t1");
	message_vision("$N����һ����ħ����ֻ����Ѫ���ϳ壬����ɱ�ˣ� !\n", this_player());
		return 1;
}
