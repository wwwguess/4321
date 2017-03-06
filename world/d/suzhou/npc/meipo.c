//NPC:/d/suzhou/npc/meipo.c
//changed by dwolf
//97.11.4

#include <ansi.h> 
inherit NPC;

string marry();
string unmarry();

void create()
{
	set_name(RED "ý��" NOR, ({ "meipo" }) );
	set("title", RED "����ׯ" NOR);
        set("gender", "Ů��" );
        set("age", 53);
        set("long",
                "һλ�����ܸɵ���ý��\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : MAG"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ"NOR,
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object marry_card1,marry_card2, obj, me;
		  object ob;
        string target,cardname;
        int i, have_marry;

        me = this_player();

		  if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg) )
                return notify_fail("�����˭�޽���Ե��\n");

		  if (marry_card1=present("marrycard",me))
			 { cardname=marry_card1->query("name");
				if (sscanf(cardname,"���%s�Ļ�Լ",target)!=1)
					{destruct(marry_card1);
					};
				if (target!=obj->query("id"))
			       return notify_fail(
                "���Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
          }

       if (present("marrycard",obj))
                return notify_fail(
               "��Ķ����Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");

        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");


        if( !living(obj) )
                return notify_fail(obj->name() + 
                "�Ѿ��޷�����޽���Ե�ˡ�\n"); 

        if(obj==me)     return notify_fail("�㲻�ܺ��Լ��޽��Լ��\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("�㲻��" + RED"AIDS"NOR + "��\n");

        if( (string)me->query("class")=="bonze" )
                return notify_fail("������ô�ܽ���أ�����\n");


        if ( (((int)me->query("age")<17)&&
                ((string)me->query("gender")=="����")) ||
              (((int)me->query("age")<14) &&
                ((string)me->query("gender")=="Ů��")) )
                return notify_fail("��̫С������ô��������\n");  

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)+"_m"))){
                message_vision(MAG "\n$N����$n˵����" 
                    + RANK_D->query_self(me) 
                    + me->name() + "��Ը���"
                    + RANK_D->query_respect(obj) + 
                "��Ϊ��\n\n"NOR, me,obj);           
        if( me->query("marks/"+obj->name(1)) ) {
                tell_object(obj, YEL + me->name() + 
                    "ȡ���˺��������ͷ��\n" NOR);
                me->set("marks/"+obj->name(1)+"_m", 0);
        }
                 me->set("marks/"+obj->name(1)+"_m", 1);
           tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ�򸾣�����Ҳ��" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� marry ָ�\n" NOR);
                write(MAG  
                        "�����㼱�����������������˵ͬ��...\n" NOR);
                return 1;
        }
        
		  if (!(marry_card1=present("marrycard",me)))
           marry_card1 = new("/obj/misc/marry_card");
        marry_card1->set("name","���"+obj->query("id")+"�Ļ�Լ");
        marry_card1->move(me);
        if (!(marry_card2=present("marrycard",obj)))
           marry_card2 = new("/obj/misc/marry_card");
        marry_card2->set("name","���"+me->query("id")+"�Ļ�Լ");
        marry_card2->move(obj);
	me->set("is_married", 1);
   obj->set("is_married", 1);
        
        message_vision(MAG "��ϲ $N �� $n ��һ�����ϲ����Ե��\n" NOR,
        obj, me);
        message("chat", me->name() + "��" + obj->name() + 
        "���ڿ�ʼ�Ƿ���\n", environment(me),me); 
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s ���ڿ�ʼ�Ƿ���! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object couple_ob;
        int i, have_marry;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        have_marry = 0;
        if (marry_card1 = present("marrycard",me)) 
                have_marry = 1;

        if (have_marry == 0)
                return notify_fail("�㻹δ�л�Լ����\n");
        
        cardname = marry_card1->query("name");
        
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
           return notify_fail("���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");
		  if (sscanf(cardname,"���%s�Ļ�Լ" ,target)!=1)
                return notify_fail("��û�а���.\n");

         if(!objectp(couple_ob = present(target, environment(me)))
                || !find_player(target) )
                return notify_fail("��İ������ڲ��ڳ�.\n");

        if ((string)couple_ob->query("gender") != "Ů��") {
                tmpstr1 = "����"; tmpstr2 = "�Ϲ�";
                str1 = "��"; str2 = "��";
        } else {
                tmpstr1 = "�Ϲ�"; tmpstr2 = "����";
                str1 = "��"; str2 = "��";
        }

        have_marry = 0;
        if (marry_card2 = present("marrycard", couple_ob))
                have_marry = 1;

        if (have_marry = 0) {
                destruct(marry_card1);                  

        message_vision(MAG " $N �� $n �����ڿ�ʼ�����Լ,�������!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s �����ڿ�ʼ�����Լ,�������! \n",
        me->name(1), couple_ob->name(1)));

                return 1;

        }

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) ) {
                message_vision(MAG "\n$N����$n˵����" 
                        + RANK_D->query_self(me) 
                        + me->name() + "�����ǽ����Լ��!����?\n\n"
                        NOR, me, couple_ob);           
                 me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
           tell_object(couple_ob, MAG "�����Ը������Լ������Ҳ"
                + "��һ�� unmarry ָ�\n" NOR);
                write(MAG  
                "������ֻ�е���" +str2 +" ͬ����...\n" NOR);
                return 1;
        }

		  destruct(marry_card1);
        destruct(marry_card2);
        
        message_vision(MAG " $N �� $n �����ڿ�ʼ�����Լ,�������!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s �����ڿ�ʼ�����Լ,�������! \n", 
        me->name(1), couple_ob->name(1)));

        return 1;
}
