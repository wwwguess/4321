//�ղ�� sb 97.11.23
#include <ansi.h>;
inherit NPC;
inherit F_CLEAN_UP;
void dzj(object);

void init()
{
//add_action("do_gao","gao");
add_action("xiao_li","dangguan");

}
void create()
{
        set_name("��������", ({ "Rong","rong","daren" }));
        set("title","�ղ��");
        set("gender", "����");
        set("age", 54);
        set("long",
                "���Ǿ��ǻ����������ղ�󳼣������ƹ��ű����Ȩ��\n"
			);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

        set("force", 1400);
        set("max_force", 800);
        set("force_factor", 10);
        set("max_gin", 200);
        set("eff_gin", 200);
        set("gin", 200);
        set("max_sen", 200);
        set("eff_sen", 200);
        set("sen", 200);

        set("combat_exp", 400000);

        set_skill("blade", 70);
        set_skill("shortsong-blade", 105);
        set_skill("force", 80);
        set_skill("wu-shun", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("fall-steps", 60);

        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("force", "wu-shun");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object("/u/sbaa/sbblade")->wield();
}
int do_gao(string str)
{
	object ob,me;
	int i;
        me=this_player();
	if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
	//ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�Ҳ�����Ҫ���ɷ���\n");
      if ( me->query("combat_exp") < ((int)ob->query("combat_exp")/5*3) )  
{call_out("dzj",1 ,me);}
 else {
        
	// moving
//	tell_room(environment(ob),"һȺ����һӵ���ϣ���"+
//	(string)ob->query("name")+"ץ������, Ȼ�������.\n", ob);
	tell_object(ob,"һȺ����һӵ���ϣ�����˵�����˸����ˣ���������һ��\n");
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"��ץ��������.\n");
	tell_object(ob,"�㷢����"+(string)me->query("name")+
	"�����.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ��ץ"+
	"����������\n",({me,ob}));
        message_vision("\n$N����$n�ȵ�����" 
		+(string)me->query("name") + "���Ҹ��ң���ȥ���ɣ���\n\n", ob, me);
              ob->kill_ob(me);}
	// ok ..}
	return 1;
}
int dzj(object crime)
{
int level,i;
int gin,kee,sen,condition;
//if (level=crime->query("crime_lv"))
 tell_object(crime,"�㾹���ܸ棿��\n");
      level=random(10);
  //      {
tell_object(crime,HIR"�����ģ���"+(string)crime->query("name")+"����ȥ��"+chinese_number(level*10)
                                +"��壡\n" );
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
                        tell_object(crime,HIR "��, ��֪����,�αص���?\n" NOR+
                        "����ѽ, ��"+(string)crime->query("name") +"����̧��ȥ!\n"+
                        "...��...��...!\n");
                        crime->unconcious();
                        crime->add("crime_lv",-1);
                        }
                message_vision(HIR "$N��$n˵��: �ٸҷ���, ��ն����!\n" NOR,this_object(),crime ); 
           //     }
       // crime->move(find_object("/d/snow/court1.c"));
        if (!crime->query("crime_lv"))
                crime->delete("crime_lv");
        }
/*else
        {
        tell_object(crime,"���ǶԲ���, ���˰��²���, ������ί����.\n");
        call_out((:call_other,crime,"move",find_object("/d/choyin/court1.c"):),1);
        }*/
 return 1;
}

int xiao_li()

 {object ob;
 ob=this_player();
    if ((ob->query("score")<1000)&&(ob->query("class")!="officer")){ command("say ��ͥ�е����˲ţ�����ʲô������");     }
else  {
	command("smile");
	command("say �ܺ�,��ͥ��������֮������" + ob->query("name") + 
        "������Ϊ��ͥЧ����������֮���ã�\n");
	ob->set("class", "officer");
}
if (ob->query("class")=="officer"){ 
       if ((ob->query("combat_exp")<10000)&&(ob->query("combat_exp")>500)) ob->set("title", "����Ժ����");
 else if (ob->query("combat_exp")<15000) ob->set("title","������ʦү");
else if (ob->query("combat_exp")<20000) ob->set("title","��������");
else if (ob->query("combat_exp")<25000) ob->set("title","ѩͤ������");
 else if (ob->query("combat_exp")<30000) ob->set("title", "ƽ������");
else if (ob->query("combat_exp")<35000) ob->set("title", "��ͬ����");
else if (ob->query("combat_exp")<40000) ob->set("title", "��������");
else if (ob->query("combat_exp")<45000) ob->set("title", "��������");
else if (ob->query("combat_exp")<50000) ob->set("title", "ͩ������");
else if (ob->query("combat_exp")<60000) ob->set("title", "������");
else if (ob->query("combat_exp")<70000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<100000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<120000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<140000) ob->set("title", "�Ͼ�֪��");
else if (ob->query("combat_exp")<160000) ob->set("title", "�����ᶽ");
else if (ob->query("combat_exp")<180000) ob->set("title", "�ƹ��ܶ�");
else if (ob->query("combat_exp")<200000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<230000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<260000) ob->set("title", "������Ա����");
else if (ob->query("combat_exp")<300000) ob->set("title", "������");
else if (ob->query("combat_exp")<360000) ob->set("title", "��������");
else if (ob->query("combat_exp")<400000) ob->set("title", "�մ���ͼ���ѧʿ");
else if (ob->query("combat_exp")<450000) ob->set("title", "��ة��");
else ob->set("title", "��ة��");
if ((ob->query("combat_exp")>550000)&&(ob->query("score")>10000)) ob->set("title", "�մ�һ��ǧ�ﲮ");
if ((ob->query("combat_exp")>620000)&&(ob->query("score")>13000)) ob->set("title", "�մͶ����򻧺�");
if ((ob->query("combat_exp")>710000)&&(ob->query("score")>16000)) ob->set("title", "�մ�һ�ȶ�����");
if ((ob->query("combat_exp")>850000)&&(ob->query("scroe")>20000)) ob->set("title", "�մͶ��Ȼ�����");
if ((ob->query("combat_exp")>1200000)&&(ob->query("score")>30000)) ob->set("title", "�մ�һ��¹����");
if ((ob->query("combat_exp")>1650000)&&(ob->query("score")>50000)) ob->set("title", "�մ��ص�ƽ����");
if ((ob->query("combat_exp")>2500000)&&(ob->query("score")>80000))
       ob->set("title", "�Ӻ�����ͳ��");
tell_object(ob,"�����ڵĹ�����[["+ob->query("title")+"]]\n");}
       return 1;
//	command("recruit " + ob->query("id") );}
 
}

