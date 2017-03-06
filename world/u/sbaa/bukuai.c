// judge_guard.c
#include <ansi.h>;
inherit NPC;
inherit F_CLEAN_UP;
void dzj(object);

init()
{
add_action("do_gao","gao");
}

void create()
{
	set_name("����", ({ "judge guard","guard" }) );
	set("gender", "����" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
���۾���ǿ��, ��������. 
LONG
);
	set("combat_exp", 8000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"����˵������Ҫ��������ȡ�֣����Ĳ�ͷ����ץȥ����!\n",
		"�������еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"����˵������������������ĵط�����\n"
	}) );

	set_skill("staff", 40);
	set_skill("unarmed", 40);
        set_skill("dodge", 80);
        set_skill("liuh-ken", 80);	
        set_skill("fall-steps", 80);
        map_skill("unarmed", "liuh-ken");
        map_skill("dodge", "fall-steps");

	setup();
	
}
int do_gao(string str)
{
	object ob,me;
	int i;
       me=this_player();
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
	//ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�Ҳ�����Ҫ���ɷ���\n");
      if (random(100)>50)  
{call_out("dzj",1 ,me);}
 else {
        
	// moving
	tell_room(environment(ob),"һȺ����һӵ���ϣ���"+
	(string)ob->query("name")+"ץ������, Ȼ�������.\n", ob);
	tell_object(ob,"һȺ����һӵ���ϣ�����˵�����˸����ˣ���������һ��\n");
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"��ץ��������.\n");
	tell_object(ob,"�㷢����"+(string)me->query("name")+
	"�����.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ��ץ"+
	"����������\n",({me,ob}));
        message_vision("\n$N����$n�ȵ�����" 
		+ me->query("name") + "���Ҹ��ң���ȥ���ɣ���\n\n", ob, me);
              ob->kill_ob(me);
	// ok ..
	return 1;}
}
int dzj(object crime)
{
int level,i;
int gin,kee,sen,condition;
//if (level=crime->query("crime_lv"))
 tell_object(this_player(),"�㾹���ܸ棿��\n");
      level=random(10);
  //      {
message_vision(HIR"�����ģ���$N����ȥ��"+chinese_number(level*10)
                                +"��壡\n",crime);
        gin=10-crime->query("max_atman")/100;
        kee=10-crime->query("max_force")/100;
        sen=10-crime->query("max_mana")/100;
        if (gin<0) gin=0;
        if (kee<0) kee=0;
        if (sen<0) sen=0;
        for (i=1;i<=level;i++)
                {
        condition=0;
                if (crime->query("eff_gin")<gin)
                        {
                        crime->set("eff_gin",1);
                        crime->set("gin",1);
                        condition++;
                        }
                crime->receive_damage("gin",gin);
                crime->receive_wound("gin",gin);
                if (crime->query("eff_kee")<kee)
                        {
                        crime->set("eff_kee",1);
                        crime->set("kee",1);
                        condition++;
                        }
                crime->receive_damage("kee",kee);
                crime->receive_wound("kee",kee);
                if (crime->query("eff_sen")<sen)
                        {
                        crime->set("eff_sen",1);
                        crime->set("sen",1);
                        condition++;
                        }
                crime->receive_damage("sen",sen);
                crime->receive_wound("sen",sen);
                if (condition==3)
                        {
                        message_vision(HIR "��, ��֪����,�αص���?\n" NOR+
                        "����ѽ, ��$N����̧��ȥ!\n"+
                        "...��...��...!\n",crime);
                        crime->unconcious();
                        crime->add("crime_lv",-1);
                        }
                message_vision(HIR "$N��$n˵��: �ٸҷ���, ��ն����!\n" NOR,this_object(),crime); 
           //     }
       // crime->move(find_object("/d/snow/court1.c"));
        if (!crime->query("crime_lv"))
                crime->delete("crime_lv");
       /* }
else
        {
        tell_object(crime,"���ǶԲ���, ���˰��²���, ������ί����.\n");
        call_out((:call_other,crime,"move",find_object("/d/choyin/court1.c"):),1);
        }*/
 return 1;
}

}
