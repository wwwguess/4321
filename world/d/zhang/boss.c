inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);

void create()
{
        set_name("����", ({ "lv si", "lv", "Lv" }) );

        set("gender", "����");
        set("age", 59);
        set("long",
                "������ò��ͨ�����������κ����ڳ��˵ĵط���
������˭���뵽�����ǽ���һ��ɱ�ְ���ϴ�\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 7000);
        set("cor", 30);
        set("int", 27);
        set("cps", 30);
	set("per",19);
        set("force", 40000);
        set("max_force", 80000);
        set("force_factor", 1000);

        set("combat_exp", 2000000);
        set("score", 200000);

        set_skill("unarmed",100);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("tie-steps", 100);
        set_skill("cloudsforce", 100);
        set_skill("fy-sword", 130);
        set_skill("sword", 110);
        map_skill("sword","fy-sword");
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 10);


        create_family("��ӥ��", 3, "����");

        setup();

        carry_object("/d/zhang/obj/csword")->wield();
}
int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num,tfinished;
        string tag = "90000";
 string *levels = ({
                        "90000",
                        "140000",
			"210000",
                        "310000",
                        "480000"
                        "660000",
                        "790000",
		"970000"
//		"1370000"
        });
        me = this_player();
// Let's see if this player still carries an un-expired task
	if ((int)me->query("combat_exp") <= 89999){
                message_vision("�����ò�мһ�˵�������$N,˵:
��ƾ������С��ɫҲ��? �������!\n",me);
		return 0;
		} 
       if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
        {
                message_vision("������$Nһ˦���䣬˵����
��û�ã����������㻹�������ҵķ��ϣ����ڸ���һ�λ��ᣮ\n", me);
           //     me->set("kee", me->query("kee")/2+1);
		tfinished = me->query("tfinished");
               me->set_temp("chishu",0);
		if (tfinished <= -10)
			me->set("tfinished", tfinished - 1);
		    else
			me->set("tfinished", 0);
        }
        }
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
//                                tag = levels[j];
                                num=j;
                                factor=10;
                                break;
                        }
        }
/*        if (num>0)
        {
                if (random(50+me->query_kar())>65)
                {
                        num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                        num=num+1;
                        factor=15;
                }
        }
*/
        if (!(tfinished =  me->query("tfinished"))) {
                me->set("tfinished",0);
                tfinished = 0;
                }
        if (tfinished >= 0) {
		num += (int) (tfinished / 3);
		if (num > sizeof(levels)-1)  
			num = sizeof(levels)-1;
		}
            else {
		num -= ((int)(-tfinished/3));
                if (num < 0) 
			 num = 0;
		}

        tag=levels[num];
 if (random(10)>2) {       quest = QUEST_D(tag)->query_quest();}
else {quest="/newquest/quest_new"->query_quest();}
        timep = quest["time"];
        time_period(timep, me);
        if (quest["quest_type"] == "Ѱ")
        {
        tell_object(me,"�һء�"+quest["quest"]+"�����ҡ�\n" NOR);
        }
                if (quest["quest_type"] == "ɱ")
        {if (random(10)>8) {tell_object(me,"�һء�"+quest["quest"]+"��ʬ�塻���ҡ�\n" NOR);
             quest["quest_type"]="Ѱ" ; quest["quest"]=quest["quest"]+"��ʬ��"; }else
        tell_object(me,"����ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
        }
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
       

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW "���Ŀ�����һ�����˵����\n����" + time + "��");
        return 1;
};
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor,awe;
        string test;
        mapping quest;
        if (ob->name(1)=="�ƽ�" ) {   who->set("quest", 0 );
               who->set_temp("chishu",0);
             tell_object(who,"����˵�����ðɣ������������ˣ�");
return 1;}
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,"����˵�����ⶫ���������Լ����Űɡ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"���ĵ����´��ٿ�һ�㣬��ξ����ˣ�\n");
                        return 1;
        }
        else
        { //destruct(ob);
        tell_object(who,"���ĵ�����ϲ�㣡���������һ������\n");
        awe=who->query_temp("chishu");who->add_temp("chishu",1);
        awe=awe+1;
        exp = (quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2))*awe;
        pot = (quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2))*awe;
        score = quest["score"]/2 + random(quest["score"]/2);
        factor=who->query("quest_factor");
        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
        }
         
// zjun
        if (who->query("score")<0)
        {
                score=score*(-1);
        }
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
       // if( bonus > 100) bonus = 100;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" +
        chinese_number(score)+"���ۺ�����\n"NOR);
        who->set("quest", 0 );
        //  destruct(ob);  
            return 1;
        }
                return 1;
}
