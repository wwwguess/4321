//tanzhi.c
//write by lysh
#include <ansi.h>

inherit F_SSERVER;
//inherit NPC;
int exert(object me, object target)
{       int taohua,force;
        object ob;
        string msg;
       
	me->this_player();  
          if (me->is_busy())
                return notify_fail("����æ����!\n");
	   if( !target ) target = offensive_target(me); 
        if(me->query_skill("lanhua-shou",1)<80 || me->query_skill("luoying-zhang",1)<80)
        return notify_fail("����һ�������Ĺ���������\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ָ��ͨ���ܶ�ս���еĶ���ʹ�á�\n");  
                 if (me->query("force")<100) return notify_fail("�����������,�޷�ʹ�á���ָ��ͨ����\n");
                 me->add("force",-75);
                taohua=me->query_skill("taohua-force",1);
                force = target->query_skill("force",1); 
                	        if(!objectp(ob=target->query_temp("weapon")) )
      {if(random(taohua*2)>force)
                   //���ֳɹ���
                   {target->start_busy(2);
                    message_vision(CYN "$Nʹ������ָ��ͨ��,��$n��ȥ,$n����һ��\n" NOR,me,target);            
                   
                    return 1;
                    }  
                    else
                    //����ʧ����
                    {message_vision(CYN "$Nʹ������ָ��ͨ��,��$n��ȥ,$n����һ��,�㿪$N�Ĺ���!\n" NOR,me,target);            
                    me->start_busy(1);
		    return 1;
	             } 
                    }
if(random(taohua)>force/2)
                  //�Ա����ɹ���
		    {  ob = target->query_temp("weapon");
                      ob->unequip();
		      ob->move(environment(target));
                    message_vision(CYN "$Nʹ������ָ��ͨ��,��$n��" NOR  +ob->name() + CYN "��ȥ! \n" NOR, me,target);
                    message_vision(CYN "$Nֻ��������" NOR + ob->name() + CYN "�ѳֲ��������ַɳ���\n" NOR,target);
                    me->start_busy(1);
		    return 1;
                     }
                   else
	            {message_vision(CYN "$Nʹ������ָ��ͨ��,��$n��ȥ,$n����һ��,�㿪$N�Ĺ���!\n" NOR,me,target);            
                    me->start_busy(1);
		    return 1;
	            } 
       
}

